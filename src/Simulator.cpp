#include "Simulator.h"

#include <Graphics/Font.hpp>
#include <Graphics/Text.hpp>
#include <Graphics/RectangleShape.hpp>
#include <Window/Event.hpp>

#include "HootFactory.h"
#include "ResourceManager.h"

Simulator::Simulator(){
    this->height = 600;
    this->width = 800;
    window.create(sf::VideoMode(this->width,this->height), "Hoot Hoot Simulator Alpha");
    ticktime = 0;
}

Simulator::~Simulator(){}

void Simulator::sim(){
    
    sf::View defaultView(sf::FloatRect(0, 0, this->width, this->height));
    sf::View currentView(sf::FloatRect(-(this->width/2), -(this->height/2), this->width, this->height));
    
    float currentZoom = 1;
    float currentZoomReciprocal = 1;
    
    ResourceManager mResourceManger;
    HootFont font = *(mResourceManger.getResource<HootFont>("../res/font/DroidSans.ttf"));
    
    // Overlay Strings
    std::string hootTitle("Hoot Hoot Simulation Alpha");
    
    sf::Clock simClock;
    float FRAME_RATE = 1.f/60.f;
    float accumulator = 0.f;
    float frameTime = 0.f;
    float totalTime = 0.f;
    
    bool pause = false;
    while (window.isOpen()){
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                window.close();
                       
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
                sf::Image Screen = window.capture();
                Screen.saveToFile("screenshot.jpg");
            }
            
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P){
                if(!pause){
                    pause = true;
                }
                else{
                    simClock.restart();
                    pause = false;
                }
            }
             
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
                currentView.reset(sf::FloatRect(-(this->width/2), -(this->height/2), this->width, this->height));
                currentZoom = 1;
                this->ticktime = 0;
                this->stage.clear();
            }
            
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::N){
                //TODO Get current options and pass to SimulatableEntityFactory
                this->stage.addSimulatableEntity(HootFactory::construct(mResourceManger, currentView.getCenter()));
            }
            
            // Enable moving of view
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                currentView.move(-10 * currentZoomReciprocal, 0);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                currentView.move(10 * currentZoomReciprocal, 0);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                currentView.move(0, -10 * currentZoomReciprocal);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                currentView.move(0, 10 * currentZoomReciprocal);
            }
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::I)){
                currentView.zoom(0.99f);
                currentZoom *= 1.01;
                currentZoomReciprocal = (1/currentZoom);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::O)){
                currentView.zoom(1.01f);
                currentZoom *= 0.99;
                currentZoomReciprocal = (1/currentZoom);
            }
            
            if(event.type == sf::Event::Resized){
                this->width = event.size.width;
                this->height = event.size.height;
                currentView.setSize(this->width, this->height);
                currentView.zoom(currentZoomReciprocal);
                defaultView.reset(sf::FloatRect(0, 0, this->width, this->height));
            }
        }
        
        window.clear();
        window.setView(currentView);
        
        frameTime = simClock.getElapsedTime().asSeconds();
        simClock.restart();
        
        // Simulate tick if not paused
        if(!pause){
            accumulator += frameTime;
            while(accumulator >= FRAME_RATE){
                this->stage.tick(FRAME_RATE);
                accumulator -= FRAME_RATE;
                this->ticktime++;
            }
            totalTime += frameTime;
        }
        this->stage.draw(&window);
        
        // Return the default view
        window.setView(defaultView);
        
        // Simulation Information
        sf::Text simVersion(hootTitle, font, 12);
        simVersion.setPosition(1, 0);
        sf::Text simTicker("Tick: "+std::to_string(this->ticktime)+
                    " - Sec: "+std::to_string(int(totalTime))+
                    " - Agents: "+std::to_string(this->stage.size())+
                    " - Pause: "+std::to_string(pause), font, 12);
        simTicker.setPosition(1, this->height - simTicker.getGlobalBounds().height);
        sf::Text simXY("X: "+std::to_string(currentView.getCenter().x)+
                    " - Y: "+std::to_string(-1* currentView.getCenter().y)+
                    " - ZM: "+std::to_string(currentZoom)+
                    " - FPS: "+std::to_string(1.f/frameTime), font, 12);
        simXY.setPosition(this->width - simXY.getGlobalBounds().width - 1, this->height - simXY.getGlobalBounds().height - 3);
        
        // Status Bar "Backgrounds"
        sf::RectangleShape statusRectLower;
        statusRectLower.setFillColor(sf::Color::Black);
        statusRectLower.setSize(sf::Vector2f(this->width, simTicker.getGlobalBounds().height));
        statusRectLower.setPosition(0, this->height - simTicker.getGlobalBounds().height);
        
        sf::RectangleShape statusRectUpper;
        statusRectUpper.setFillColor(sf::Color::Black);
        statusRectUpper.setSize(sf::Vector2f(this->width, simVersion.getGlobalBounds().height));
        statusRectUpper.setPosition(0,0);
        
        // Draw on Window
        window.draw(statusRectUpper);
        window.draw(simVersion);
        
        window.draw(statusRectLower);
        window.draw(simTicker);
        window.draw(simXY);

        window.display();
    }
}