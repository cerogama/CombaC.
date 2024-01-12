#include <SFML/Graphics.hpp>
#include <sstream>
#include <Box2D/Box2D.h>



constexpr float SCALE = 30.0f;

class Ball {
public:
    Ball(b2World &world, float x, float y, int dynamic, float density = 0.0f){
        b2BodyDef bodyDef;
        bodyDef.position.Set(x / SCALE, y / SCALE);
        bodyDef.angularDamping = 0.01f;

        switch (dynamic) {
            case 0:
                bodyDef.type = b2_staticBody;
                break;
            case 1:

                break;
            case 2:
                bodyDef.type = b2_kinematicBody;
                break;
        }

        body = world.CreateBody(&bodyDef);

        b2CircleShape shapeBall;
        shapeBall.m_radius = 15.0f / SCALE;

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &shapeBall;
        fixtureDef.density = density;
        fixtureDef.restitution = 0.5f;

        body->CreateFixture(&fixtureDef);
        /*
        b2PolygonShape shape;

        shape.SetAsBox(x/SCALE, y/SCALE);

        b2FixtureDef fixturedef;

        fixturedef.shape = &shape;
        fixturedef.restitution = 0.5f;
        fixturedef.density = Density;*/

        sphere.setRadius(15.0);
        sphere.setFillColor(sf::Color::Red);
        sphere.setOrigin(100,300);

    }

    void update(){
        sphere.setPosition(SCALE * body->GetPosition().x, SCALE * body->GetPosition().y);
        sphere.setRotation(body->GetAngle() * 180 / b2_pi);

    }

    void draw(sf::RenderWindow &win) const{
        win.draw(sphere);
    }

    void resetPosition() {
        body->SetTransform(b2Vec2(0.f, 0.f), body->GetAngle());
    }

    void stop() {
        body->SetLinearVelocity(b2Vec2(0, 0));
    }

    b2Body *getBody() {
        return body;
    }

private:
    sf::CircleShape sphere;
    b2Body *body;
};

class Bottle : public b2ContactListener{
public:
    Bottle(b2World &world, float x, float y, int dynamic,  float density = 0.0f){
        b2BodyDef bodyDef;
        bodyDef.position.Set(x / SCALE, y / SCALE);

        switch (dynamic) {
            case 0:
                bodyDef.type = b2_staticBody;
                break;
            case 1:
                bodyDef.type = b2_dynamicBody;
                break;
            case 2:
                bodyDef.type = b2_kinematicBody;
                break;
        }

       

        body = world.CreateBody(&bodyDef);

        b2CircleShape ShapeButle;

        ShapeButle.m_radius = 15.0f/ SCALE;

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &ShapeButle;
        fixtureDef.restitution = 0.5f;
        fixtureDef.density = density;

        body->CreateFixture(&fixtureDef);


        buttle.setRadius(15.0);
        buttle.setFillColor(sf::Color::Green);
        buttle.setOrigin(100,300);

    }

    void BeginContact(b2Contact* contact)
    {
        int16 hitN = 0;
    }

    void update(){
        buttle.setPosition(SCALE * body->GetPosition().x, SCALE * body->GetPosition().y);
        buttle.setRotation(body->GetAngle() * 180 / b2_pi);

    }

    void draw(sf::RenderWindow &win) const{
        win.draw(buttle);
    }

    void resetPosition() {
        body->SetTransform(b2Vec2(0.f, 0.f), body->GetAngle());
    }

    void stop() {
        body->SetLinearVelocity(b2Vec2(0, 0));
    }

    b2Body *getBody() {
        return body;
    }

private:
    sf::CircleShape buttle;
    b2Body *body;
};
class PlataformTop {
public:
    PlataformTop(b2World &world, float x, float y,int dynamic = 0, float Density = 1.0f) {
        b2BodyDef bodyDefP;
        bodyDefP.position.Set(x / SCALE, y / SCALE);
        bodyDefP.fixedRotation = true;

        switch (dynamic) {
            case 0:
                bodyDefP.type = b2_staticBody;
                break;
            case 1:
                bodyDefP.type = b2_dynamicBody;
                break;
            case 2:
                bodyDefP.type = b2_kinematicBody;
                break;
        }

        body = world.CreateBody(&bodyDefP);

        b2PolygonShape shape;
        //Le da las dimenciones del colider, primero iria la altura en x, despues en y, creo que son independientes
        // de la posicion en donde se genera el cubo, si lo dividimos por la escala hace cosas raras, asi que mejor dejalo en valores
        // normales
        shape.SetAsBox(900.0f, 3.0f);

        b2FixtureDef fixturedef;

        fixturedef.shape = &shape;
        fixturedef.restitution = 0.5f;
        fixturedef.density = Density;

        body->CreateFixture(&fixturedef);

        /*LBox.setSize(sf::Vector2f(x, -y/SCALE));
        LBox.setFillColor(sf::Color::White);
        LBox.setOrigin(0.0f, 195.0f);*/
    }

    void SetAsBox(float hx,float hy){

    }
    void SetAsBox(float hx,float hy, const b2Vec2& center,float angle){

    }

    void update() {
        LBox.setPosition(SCALE * body->GetPosition().x, SCALE * body->GetPosition().y);

        /*LBox.setRotation(body->GetAngle() * 180 / b2_pi);*/

    }

    void draw(sf::RenderWindow &win) const {
        win.draw(LBox);
    }

    void resetPosition() {
        body->SetTransform(b2Vec2(0, 0), body->GetAngle());
    }

    void stop() {
        body->SetLinearVelocity(b2Vec2(0, 0));
    }

    b2Body *getBody() {
        return body;
    }

private:

    sf::RectangleShape LBox;
    b2Body *body;

};
class PlataformBottom {
public:
    PlataformBottom(b2World &world, float x, float y,int dynamic = 0, float Density = 1.0f) {
        b2BodyDef bodyDefP;
        bodyDefP.position.Set(x / SCALE, y / SCALE);
        bodyDefP.fixedRotation = true;

        switch (dynamic) {
            case 0:
                bodyDefP.type = b2_staticBody;
                break;
            case 1:
                bodyDefP.type = b2_dynamicBody;
                break;
            case 2:
                bodyDefP.type = b2_kinematicBody;
                break;
        }

        body = world.CreateBody(&bodyDefP);

        b2PolygonShape shape;
        //Le da las dimenciones del colider, primero iria la altura en x, despues en y, creo que son independientes
        // de la posicion en donde se genera el cubo, si lo dividimos por la escala hace cosas raras, asi que mejor dejalo en valores
        // normales
        shape.SetAsBox(900.0f, 3.0f);

        b2FixtureDef fixturedef;

        fixturedef.shape = &shape;
        fixturedef.restitution = 0.5f;
        fixturedef.density = Density;

        body->CreateFixture(&fixturedef);

        LBox.setSize(sf::Vector2f(x, -y/SCALE));
        LBox.setFillColor(sf::Color::White);
        LBox.setOrigin(-200.0f, -330.0f);
    }

    void SetAsBox(float hx,float hy){

    }
    void SetAsBox(float hx,float hy, const b2Vec2& center,float angle){

    }

    void update() {
        LBox.setPosition(SCALE * body->GetPosition().x, SCALE * body->GetPosition().y);

        /*LBox.setRotation(body->GetAngle() * 180 / b2_pi);*/

    }

    void draw(sf::RenderWindow &win) const {
        win.draw(LBox);
    }

    void resetPosition() {
        body->SetTransform(b2Vec2(0, 0), body->GetAngle());
    }

    void stop() {
        body->SetLinearVelocity(b2Vec2(0, 0));
    }

    b2Body *getBody() {
        return body;
    }

private:

    sf::RectangleShape LBox;
    b2Body *body;

};

class BorderL {
public:
    BorderL(b2World &world, float x, float y, int dynamic = 0, float Density = 1.0f) {
        b2BodyDef bodyDef;
        bodyDef.position.Set(x / SCALE, y / SCALE);
        bodyDef.fixedRotation = true;

        switch (dynamic) {
            case 0:
                bodyDef.type = b2_staticBody;
                break;
            case 1:
                bodyDef.type = b2_dynamicBody;
                break;
            case 2:
                bodyDef.type = b2_kinematicBody;
                break;
        }

        body = world.CreateBody(&bodyDef);

        b2PolygonShape polygon;

        polygon.SetAsBox(3.0f,900.0f);

        b2FixtureDef fixturedef;

        fixturedef.shape = &polygon;
        fixturedef.restitution = 0.5f;
        fixturedef.density = Density;

        body->CreateFixture(&fixturedef);

        /*/Le da las dimenciones del colider
        shape.SetAsBox(x/SCALE, y/SCALE);

        b2FixtureDef fixturedef;

        fixturedef.shape = &shape;
        fixturedef.restitution = 0.5f;
        fixturedef.density = Density;



        body->CreateFixture(&fixturedef);

        // la medida para poder realizar las coliciones deacuerdo con el shape es 1.72
        LBox.setSize(sf::Vector2f(x*1.72f, y*1.72f));
         LBox.setFillColor(sf::Color::White);
         LBox.setOrigin(50.0f, 50.0f);*/


        LBox.setSize(sf::Vector2f(x/SCALE, y));
        LBox.setFillColor(sf::Color::Blue);
        LBox.setOrigin(0.0f, 0.0f);
    }

    void update() {
        LBox.setPosition(SCALE * body->GetPosition().x, SCALE * body->GetPosition().y);
        /*LBox.setRotation(body->GetAngle() * 180 / b2_pi);*/
    }

    void draw(sf::RenderWindow &win) const {
        win.draw(LBox);
    }

    void resetPosition() {
        body->SetTransform(b2Vec2(100.0f, 100.0f), body->GetAngle());
    }

    void stop() {
        body->SetLinearVelocity(b2Vec2(0, 0));
    }

    b2Body *getBody() {
        return body;
    }

private:

    sf::RectangleShape LBox;
    b2Body *body;

};
class BorderR {
public:
    BorderR(b2World &world, float x, float y, int dynamic = 0, float Density = 1.0f) {
        b2BodyDef bodyDef;
        bodyDef.position.Set(x / SCALE, y / SCALE);
        bodyDef.fixedRotation = true;

        switch (dynamic) {
            case 0:
                bodyDef.type = b2_staticBody;
                break;
            case 1:
                bodyDef.type = b2_dynamicBody;
                break;
            case 2:
                bodyDef.type = b2_kinematicBody;
                break;
        }

        body = world.CreateBody(&bodyDef);

        b2PolygonShape polygon;

        //configura el colider del lado derecho
        polygon.SetAsBox(3.0f,900.0f);

        b2FixtureDef fixturedef;

        fixturedef.shape = &polygon;
        fixturedef.restitution = 0.5f;
        fixturedef.density = Density;

        body->CreateFixture(&fixturedef);


        /*RBox.setSize(sf::Vector2f(3.0f, 900.0f));
         RBox.setFillColor(sf::Color::Blue);
         RBox.setOrigin(175.f, 0.f);*/
    }

    void update() {
        RBox.setPosition(SCALE * body->GetPosition().x, SCALE * body->GetPosition().y);
        /*LBox.setRotation(body->GetAngle() * 180 / b2_pi);*/
    }

    void draw(sf::RenderWindow &win) const {
        win.draw(RBox);
    }

    void resetPosition() {
        body->SetTransform(b2Vec2(100.0f, 100.0f), body->GetAngle());
    }

    void stop() {
        body->SetLinearVelocity(b2Vec2(-100, 0));
    }

    b2Body *getBody() {
        return body;
    }

private:

    sf::RectangleShape RBox;
    b2Body *body;

};
class Center {
public:
    Center(b2World &world, float x, float y, int dynamic = 0, float Density = 1.0f) {
        b2BodyDef bodyDef;
        bodyDef.position.Set(x / SCALE, y / SCALE);
        bodyDef.fixedRotation = true;

        switch (dynamic) {
            case 0:
                bodyDef.type = b2_staticBody;
                break;
            case 1:
                bodyDef.type = b2_dynamicBody;
                break;
            case 2:
                bodyDef.type = b2_kinematicBody;
                break;
        }

        body = world.CreateBody(&bodyDef);

        b2PolygonShape shape;


        //Le da las dimenciones del colider con relacion a x y, y
        shape.SetAsBox(0.3f, 4.0f);


        b2FixtureDef fixturedef;
        fixturedef.shape = &shape;
        fixturedef.restitution = 0.5f;
        fixturedef.density = Density;

        body->CreateFixture(&fixturedef);

        CBox.setSize(sf::Vector2f(16.0f, 260.0f));
        CBox.setFillColor(sf::Color::White);
        CBox.setOrigin(92.0f, 410.0f);
    }



    void update() {
        CBox.setPosition(SCALE * body->GetPosition().x, SCALE * body->GetPosition().y);
        /*LBox.setRotation(body->GetAngle() * 180 / b2_pi);*/

    }

    void draw(sf::RenderWindow &win) const {
        win.draw(CBox);
    }

    void resetPosition() {
        body->SetTransform(b2Vec2(0, 0), body->GetAngle());
    }

    void stop() {
        body->SetLinearVelocity(b2Vec2(0, 0));
    }

    b2Body *getBody() {
        return body;
    }

private:

    sf::RectangleShape CBox;
    b2Body *body;

};
class Cube {
public:
    Cube(b2World &world, float x, float y, int dynamic = 0,float density = 0.0f) {
        b2BodyDef bodydef;
        bodydef.position.Set(x / SCALE, y / SCALE);
        bodydef.fixedRotation = true;

        switch (dynamic) {
            case 0:
                bodydef.type = b2_staticBody;
                break;
            case 1:
                bodydef.type = b2_dynamicBody;
                break;
            case 2:
                bodydef.type = b2_kinematicBody;
                break;
        }


        body = world.CreateBody(&bodydef);

        b2PolygonShape shape;
        shape.SetAsBox(30.0f/ SCALE, 30.0f/SCALE);
        // shape.SetAsBox(10.0f, 250.0f);


        b2FixtureDef fixturedef;
        fixturedef.shape = &shape;
        fixturedef.density = density;
        fixturedef.restitution = 0.5f;

        body->CreateFixture(&fixturedef);


        box.setSize(sf::Vector2f(10.0f, 10.0f));
        box.setFillColor(sf::Color::Red);
        box.setOrigin(0.0f, 0.0f);
    }


    void update() {
        box.setPosition(SCALE * body->GetPosition().x, SCALE * body->GetPosition().y);
        box.setRotation(body->GetAngle() * 180 / b2_pi);
    }

    void draw(sf::RenderWindow &win) const {
        win.draw(box);
    }

    void resetPosition() {
        body->SetTransform(b2Vec2(8, 7), body->GetAngle());

    }

    void stop() {
        body->SetLinearVelocity(b2Vec2(0, 0));
    }

    b2Body *getBody() {
        return body;
    }

private:
    sf::RectangleShape box;
    b2Body *body;
};

int main() {

    //Clock Game
    sf::Clock clock;


    //Game Run
    bool paused = true;

    //---------------------------------------------------//
    //Score And textur whit SFML
    int Score_P1 = 0;
    int Score_P2 = 0;

    //Draw some text
    sf::Text MessageText;
    sf::Text Score_P1_Text;
    sf::Text Score_P2_Text;

    //Import fonds;
    sf::Font font;
    font.loadFromFile("C:\\Users\\flete\\Documents\\CombaCompleta\\Fonds\\The Led Display St.ttf");

    //Set The font
    MessageText.setFont(font);
    Score_P1_Text.setFont(font);
    Score_P2_Text.setFont(font);

    //Assign Massage
    MessageText.setString("Press enter to start");
    Score_P1_Text.setString("P1: ");
    Score_P2_Text.setString(" :P2");

    //make it big
    MessageText.setCharacterSize(50);
    Score_P1_Text.setCharacterSize(40);
    Score_P2_Text.setCharacterSize(40);

    //Chose a color
    MessageText.setFillColor(sf::Color::Red);
    Score_P1_Text.setFillColor(sf::Color::White);
    Score_P2_Text.setFillColor(sf::Color::White);

    //Position text
    sf::FloatRect textRect = MessageText.getGlobalBounds();
    MessageText.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
    MessageText.setPosition(1600/2.0f,800/2.0f);

    Score_P1_Text.setPosition(20, 20);
    Score_P2_Text.setPosition(1500, 20);

    //----------------------------------------------//

    sf::RenderWindow window(sf::VideoMode(1600, 800), "Space Invaders v0.0.1!");

    b2Vec2 gravity(0.0f, 0.0f);
    b2World world(gravity);

    //colider left
    BorderL borderL(world, 0, 10, 0, 0.0f);

    //center
    Center center(world, 850, 650, 0, 0.0f);

    //colider Rigth
    BorderR borderR(world, 1773, 0, 0, 0.0f);
    //colider Top
    PlataformTop plataformT(world, 800.0f, 200.0f, 0, 0.0f);
    //colider Buttom
    PlataformBottom plataformB(world, 10, 1170, 0, 0.0f);

    //bolitaXD
    Ball bolita(world, 700, 500, 1, 0.1f);

    Bottle buttle(world, 400, 650, 0,10.0f);
    Bottle buttle1(world, 1400, 650, 0,10.0f);





/*
     Border border1(world ,1600,0,0,1.0f);*/



    /*  Cube cube(world, 400, 300,0,1.0f);

     Cube cube1(world, 800, 300,1,0.f);

       Cube cube2(world, 500, 300, 0.0f);

       Cube cube3(world, 600, 400, 1,100000.f);

       b2PrismaticJointDef jointDef;
       jointDef.Initialize(cube.getBody(), cube3.getBody(), cube3.getBody()->GetWorldCenter(), b2Vec2(1.0f, 0.0f));
       jointDef.lowerTranslation = -10.0f;
       jointDef.upperTranslation = 10.0f;
       jointDef.enableLimit = false;

       b2PrismaticJointDef jointDef2;
       jointDef2.Initialize(cube2.getBody(), cube3.getBody(), cube3.getBody()->GetWorldCenter(), b2Vec2(0.0f, 1.0f));
       jointDef2.lowerTranslation = -10.0f;
       jointDef2.upperTranslation = 10.0f;
       jointDef2.enableLimit = false;


       Cube cube4(world, 50, 50, 1);

       b2RevoluteJointDef jointDef3;

       jointDef3.Initialize(cube4.getBody(), cube3.getBody(), cube3.getBody()->GetWorldCenter());
       jointDef3.lowerAngle = -10.0f * b2_pi / 180.0f;
       jointDef3.upperAngle = 10.0f * b2_pi / 180.0f;
       jointDef3.enableLimit = false;
       jointDef3.enableMotor = false;
       jointDef3.maxMotorTorque = 1.0f;
       jointDef3.motorSpeed = 1.0f;


       b2PrismaticJoint* joint = (b2PrismaticJoint*)world.CreateJoint(&jointDef);
       b2PrismaticJoint* joint2 = (b2PrismaticJoint*)world.CreateJoint(&jointDef2);
       b2RevoluteJoint* joint3 = (b2RevoluteJoint*)world.CreateJoint(&jointDef3);

       b2GearJointDef gearJointDef;

       gearJointDef.bodyA = cube.getBody();
       gearJointDef.bodyB = cube2.getBody();
       gearJointDef.joint1 = joint;
       gearJointDef.joint2 = joint2;
       gearJointDef.ratio = 0.2f;

       world.CreateJoint(&gearJointDef);


       //Pulley Joint

       Cube myBody1(world, 600, 600, 1,1.0f);
       Cube myBody2(world, 700, 600, 1,1.0f);

       b2Vec2 anchor1 = myBody1.getBody()->GetWorldCenter();
       b2Vec2 anchor2 = myBody2.getBody()->GetWorldCenter();

       b2Vec2 p1= myBody1.getBody()->GetPosition();
       b2Vec2 p2= myBody2.getBody()->GetPosition();

       b2Vec2 groundAnchor1(p1.x, p1.y + 50.0f);
       b2Vec2 groundAnchor2(p2.x, p2.y + 52.0f);

       float ratio = 1.0f;

       b2PulleyJointDef pulleyjointDef;
       pulleyjointDef.Initialize(myBody1.getBody(), myBody2.getBody(), groundAnchor1, groundAnchor2, anchor1, anchor2, ratio);
   */

    //  world.CreateJoint(&pulleyjointDef);

    // myBody1.getBody()->ApplyForce(b2Vec2(0.0f, -0.1f), myBody1.getBody()->GetWorldCenter(), true);



    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {

            //paused system
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
            {
                paused = false;
                MessageText.setPosition(1600/2.0f,-50);
                clock.restart();
            }

            if(!paused)
            {

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                    /*   cube.getBody()->SetLinearVelocity(b2Vec2(0.1f, 0.0f));
                    cube2.getBody()->ApplyForceToCenter(b2Vec2(0.1f, 0.0f), true);*/

                    bolita.getBody()->ApplyForceToCenter(b2Vec2(0.2f, 0.03f), true);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                    // cube.getBody()->ApplyForceToCenter(b2Vec2(-0.1f, 0.0f),true);
                    // cube2.getBody()->ApplyForceToCenter(b2Vec2(-0.1f, 0.0f), true);
                    bolita.getBody()->ApplyForceToCenter(b2Vec2(-0.2f, 0.0f),true);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                    /* cube.getBody()->ApplyForceToCenter(b2Vec2(0.0f, 0.1f), true);
                     cube2.getBody()->ApplyForceToCenter(b2Vec2(0.0f, -0.1f), true);*/

                    bolita.getBody()->ApplyForceToCenter(b2Vec2(0.f, -0.2f), true);

                    // cube.getBody()->SetLinearVelocity(b2Vec2(0.f, -1.0f));

                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                    /*  cube.getBody()->SetLinearVelocity(b2Vec2(0.0f, 0.1f));
                      cube2.getBody()->ApplyForceToCenter(b2Vec2(0.0f, 0.1f), true);*/

                    bolita.getBody()->ApplyForceToCenter(b2Vec2(0.f, 0.2f),true);

                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    // cube.resetPosition();

                    bolita.resetPosition();

                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
                    // cube.stop();
                    // cube2.stop();
                    bolita.stop();
                }


            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
                window.close();
            }
            

        }

        world.Step(1 / 60.f, 8, 3);


        /* borderR.update();*/

        buttle.update();
        buttle1.update();
/*
         border1.update();*/
        bolita.update();
        plataformB.update();
        plataformT.update();
        borderL.update();
        borderR.update();
        center.update();

        /*  cube2.update();
            cube2.update();
           cube3.update();
           cube4.update();
           myBody1.update();
           myBody2.update();*/

        window.clear();

        //cosas estaticas




        buttle.draw(window);
        buttle1.draw(window);
        center.draw(window);
/*
        border1.draw(window);*/
        borderR.draw(window);
        bolita.draw(window);
        plataformB.draw(window);
        borderL.draw(window);
        plataformT.draw(window);


        //players draw
        window.draw(MessageText);
        window.draw(Score_P1_Text);
        window.draw(Score_P2_Text);


        /*  cube2.draw(window);
       cube2.draw(window);
         cube3.draw(window);
         cube4.draw(window);
         myBody1.draw(window);
         myBody2.draw(window);*/
        window.display();
    }
    return 0;
}
