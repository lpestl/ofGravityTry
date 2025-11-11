#include "ofGradientCircle.h"

ofGradientCircle::~ofGradientCircle()
{
}

void ofGradientCircle::setup(float x, float y, float radius, const ofColor& color)
{
	circle::setup(x, y, radius);
	setup(color);
}

void ofGradientCircle::setup(float x, float y, float radius)
{
	circle::setup(x, y, radius);
	setup(ofColor(0, 0, 255, 255));
}

void ofGradientCircle::setup(const ofColor& color)
{
	_color = color;
	setup();
}

void ofGradientCircle::setup() {	
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
}

void ofGradientCircle::update() {
    // Move the circle down
    setPosition(getPosition().x, getPosition().y + 1.0f);
}

void ofGradientCircle::draw() {
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
	ofTranslate(getPosition().x, getPosition().y);
	_circleMesh.draw();
	ofPopMatrix();

	_gradientShader.end();
}

void ofGradientCircle::setColor(const ofColor & newColor) {
	_color = newColor;
	createCircleMesh();
}

ofColor ofGradientCircle::getColor() const {
	return _color;
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

		_circleMesh.addVertex(ofVec3f(x * getRadius(), y * getRadius(), 0));
		_circleMesh.addTexCoord(ofVec2f((x + 1) * 0.5, (y + 1) * 0.5));
	}
}
