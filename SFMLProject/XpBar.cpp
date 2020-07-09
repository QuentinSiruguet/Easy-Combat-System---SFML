#include "XpBar.h"



void XpBar::initXpBar(float experience, float experienceMax)
{
	this->experience = experience;
	this->experienceMax = experienceMax;
	this->window = nullptr;


	this->xpBarFrame.setFillColor(sf::Color(255, 255, 255, 0));
	this->xpBar.setFillColor(sf::Color(38, 133, 80, 128));
	this->xpBarFrame.setOutlineThickness(5.f);
	this->xpBarFrame.setOutlineColor(sf::Color(38, 6, 87));
}

XpBar::XpBar()
{
}

XpBar::XpBar(float experience, float experienceMax)
{
	this->initXpBar(experience, experienceMax);
}


XpBar::~XpBar()
{
}

void XpBar::update(sf::RenderWindow *window, float experience, float experienceMax)
{
	this->window = window;
	this->xpBarFrame.setSize(sf::Vector2f((window->getSize().x / 5) * 3, 20));

	if (this->experience >= 0)
		this->xpBar.setSize(sf::Vector2f((experience * this->xpBarFrame.getSize().x) / experienceMax, 20));
	sf::Vector2f xpBarFramePosView = this->window->mapPixelToCoords(sf::Vector2i(this->window->getSize().x / 5,this->window->getSize().y - this->xpBarFrame.getSize().y - this->xpBarFrame.getOutlineThickness()), this->window->getView());

	this->xpBarFrame.setPosition(xpBarFramePosView.x, xpBarFramePosView.y);
	this->xpBar.setPosition(this->xpBarFrame.getPosition());
}

void XpBar::render(sf::RenderTarget * target)
{
	target->draw(this->xpBarFrame);
	target->draw(this->xpBar);
}
