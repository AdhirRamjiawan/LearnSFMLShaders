#include <SFML/Graphics.hpp>

#include <iostream>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    sf::RenderTexture screenTexture;

    if (!sf::Shader::isAvailable())
    {
        // shaders are not available...
    }

    sf::Shader shader;

    const std::string vertexShader = R"(
uniform float stime;

 void main(void)
  {
 // transform the vertex position
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;

    // transform the texture coordinates
    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;

    // forward the vertex color
    gl_FrontColor = gl_Color;
  }

)";

    const std::string fragmentShader = R"(
// SIMPLE FADE IN/OUT SHADER
uniform sampler2D texture;
uniform float stime;

void main()
{
    // lookup the pixel in the texture
    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);

    pixel.a = sin(stime);

    // multiply it by the color
    gl_FragColor = gl_Color * pixel ;

})";

    // load both shaders
    if (!shader.loadFromMemory(vertexShader, fragmentShader))
    {
        std::cout << "error loading shader" << std::endl;
    }

    //shader.setParameter("texture", sf::Shader::CurrentTexture);
    
    screenTexture.create(500, 500);
    shader.setParameter("texture", screenTexture.getTexture());

    sf::RectangleShape rec;
    sf::RectangleShape rec2;

    rec.setFillColor(sf::Color::Red);
    rec.setSize(sf::Vector2f(50, 50));
    rec.setPosition(sf::Vector2f(100, 100));

    rec2.setFillColor(sf::Color::Blue);
    rec2.setSize(sf::Vector2f(50, 50));
    rec2.setPosition(sf::Vector2f(400, 400));

    

    sf::Clock time;
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        screenTexture.clear();
        
        screenTexture.draw(rec);
        screenTexture.draw(rec2);

        screenTexture.display();
        
        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
         sf::Sprite ppSprite(screenTexture.getTexture());

        //window.draw(ppSprite);
        
        window.draw(ppSprite, &shader);
        
        //std::cout << time.getElapsedTime().asMilliseconds() << " " << sin(time.getElapsedTime().asMilliseconds()) << std::endl;

        shader.setParameter("stime", time.getElapsedTime().asSeconds());

        // end the current frame
        window.display();
    }

    return 0;
}