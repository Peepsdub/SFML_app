#include "Animation.h"

Animation::Animation(Texture* texture, Vector2u imageCount, float switchTime) {

	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;

	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);
}

Animation::~Animation() {

}

void Animation::Update(float deltaTime) {
	totalTime += deltaTime;

	if (totalTime >= switchTime) {
		totalTime -= switchTime;

		currentImage.x++;

		if (currentImage.x >= imageCount.x) {
			currentImage.x = 0;
			currentImage.y++;
		}

		if (currentImage.y >= imageCount.y) {
			currentImage.y = 0;
		}
	}

	uvRect.left = currentImage.x * uvRect.width;
	uvRect.top = currentImage.y * uvRect.height;
}
