#include "ofGradientCircle.h"

ofGradientCircle::ofGradientCircle()
	: _posX(0.0f)
	, _posY(0.0f)
	, _radius(100.0f)
	, _color(255, 0, 0, 255)
	, _useShader(true) {
}

ofGradientCircle::ofGradientCircle(float x, float y, float radius, const ofColor & circleColor)
	: _useShader(true) {
	_posX = x;
	_posY = y;
	_radius = radius;
	_color = circleColor;
}

void ofGradientCircle::setup(bool useShader) {
	_useShader = useShader;
	if (_useShader) {
		// Загружаем шейдер для градиента
		string fragmentShader = R"(
            #version 120

            uniform vec2 u_center;
            uniform float u_radius;
            uniform vec4 u_color;

            void main() {
                // Вычисляем расстояние от центра
                vec2 position = gl_TexCoord[0].xy;
                float distance = length(position - u_center);

                // Нормализуем расстояние
                float normalizedDistance = clamp(distance / u_radius, 0.0, 1.0);

                // Вычисляем альфа-канал (1 в центре, 0 на краю)
                float alpha = 1.0 - normalizedDistance;

                // Применяем цвет с градиентной прозрачностью
                gl_FragColor = vec4(u_color.rgb, u_color.a * alpha);
            }
        )";

		_gradientShader.setupShaderFromSource(GL_FRAGMENT_SHADER, fragmentShader);
		_gradientShader.linkProgram();

		createCircleMesh();
	} else {
		createGradientTexture();
	}
}

void ofGradientCircle::update() {}

void ofGradientCircle::draw() {
	if (_useShader) {
		// Шейдерная версия - более плавная и эффективная
		_gradientShader.begin();

		_gradientShader.setUniform2f("u_center", 0.5, 0.5);
		_gradientShader.setUniform1f("u_radius", 0.5);
		_gradientShader.setUniform4f("u_color",
			_color.r / 255.0f,
			_color.g / 255.0f,
			_color.b / 255.0f,
			_color.a / 255.0f);

		ofPushMatrix();
		ofTranslate(_posX, _posY);
		_circleMesh.draw();
		ofPopMatrix();

		_gradientShader.end();
	} else {
		// Версия с текстурой
		ofSetColor(255, 255, 255, 255);
		_gradientTexture.draw(_posX - _radius, _posY - _radius);
	}
}

void ofGradientCircle::setRadius(float newRadius) {
	_radius = newRadius;
	if (_useShader) {
		createCircleMesh();
	} else {
		createGradientTexture();
	}
}

float ofGradientCircle::getRadius() const {
	return _radius;
}

void ofGradientCircle::setPosition(float x, float y) {
	_posX = x;
	_posY = y;
}

ofVec2f ofGradientCircle::getPosition() const {
    return ofVec2f(_posX, _posY);
}

void ofGradientCircle::setColor(const ofColor & newColor) {
	_color = newColor;
	if (_useShader) {
		createCircleMesh();
	} else {
		createGradientTexture();
	}
}

ofColor ofGradientCircle::getColor() const {
	return _color;
}

void ofGradientCircle::createGradientTexture() {
	ofImage gradientImage;
	int size = _radius * 2;
	gradientImage.allocate(size, size, OF_IMAGE_COLOR_ALPHA);

	ofColor centerColor = _color;
	centerColor.a = 255;

	ofColor edgeColor = _color;
	edgeColor.a = 0;

	float centerX = size / 2.0f;
	float centerY = size / 2.0f;

	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			float dx = x - centerX;
			float dy = y - centerY;
			float distance = sqrt(dx * dx + dy * dy);
			float normalizedDistance = ofClamp(distance / _radius, 0.0f, 1.0f);

			ofColor pixelColor;
			pixelColor.r = ofLerp(centerColor.r, edgeColor.r, normalizedDistance);
			pixelColor.g = ofLerp(centerColor.g, edgeColor.g, normalizedDistance);
			pixelColor.b = ofLerp(centerColor.b, edgeColor.b, normalizedDistance);
			pixelColor.a = ofLerp(centerColor.a, edgeColor.a, normalizedDistance);

			gradientImage.setColor(x, y, pixelColor);
		}
	}

	_gradientTexture.loadData(gradientImage);
}

void ofGradientCircle::createCircleMesh() {
	_circleMesh.clear();
	_circleMesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);

	// Центральная точка
	_circleMesh.addVertex(ofVec3f(0, 0, 0));
	_circleMesh.addTexCoord(ofVec2f(0.5, 0.5));

	// Точки по окружности
	int segments = 64;
	for (int i = 0; i <= segments; i++) {
		float angle = ofMap(i, 0, segments, 0, TWO_PI);
		float x = cos(angle);
		float y = sin(angle);

		_circleMesh.addVertex(ofVec3f(x * _radius, y * _radius, 0));
		_circleMesh.addTexCoord(ofVec2f((x + 1) * 0.5, (y + 1) * 0.5));
	}
}



