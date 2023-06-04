#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofEnableDepthTest();

	auto ico_sphere = ofIcoSpherePrimitive(250, 7);
	this->mesh = ico_sphere.getMesh();
}

//--------------------------------------------------------------
void ofApp::update() {

	this->mesh.clearColors();

	ofSeedRandom(39);

	for (int i = 0; i < this->mesh.getNumVertices(); i++) {

		auto noise_value = ofNoise(glm::vec4(this->mesh.getVertex(i) * 0.008, ofGetFrameNum() * 0.03));
		int int_noise_value = noise_value;
		float param = noise_value - int_noise_value;
		param = abs(param - 0.5);
		
		auto value = param < 0.1 ? ofMap(param, 0, 0.1, 255, 39) : 39;
		auto color = ofColor(0, 0, value);
		this->mesh.addColor(color);
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateY(ofGetFrameNum() * 0.7777);
	ofRotateX(ofGetFrameNum() * 1.15);

	this->mesh.drawFaces();

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}