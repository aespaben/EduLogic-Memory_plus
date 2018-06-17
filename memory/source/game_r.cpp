/**
 * @file game_r.cpp
 * @author Angel España - GitHub aespaben
 * @author Patricia Daboin - GitHub apdaboin
 */

#include "headers/game_r.h"
Game_r::Game_r(QGraphicsView* parent): QGraphicsView(parent)
{
    //Creating scene
    this->scene = new QGraphicsScene();

    //Setting current total cards
    this->total_cards = 0;

    //Disabling scroll bars (view)
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //Setting fixed size (view)
    setFixedSize(800,600);

    //Setting view name and icon
    setWindowTitle(QString("Memoria Relacional"));
    setWindowIcon(QIcon("://imgs/colorful-brain+.png"));

    //Centering the window
    QRect rect = QApplication::desktop()->screenGeometry();
    this->move(rect.width()/2 - this->width()/2, rect.height()/2 - this->height()/2);

    //Setting scene rect size
    this->scene->setSceneRect(0,0,800,600);

    //Setting scene to view
    setScene(scene);
}

/*************************************************************************************/
//Class destructor
Game_r::~Game_r()
{
    //Clearing the scene
    this->clean_scene(true);

    //Deleting scene
    delete this->scene;
}

/*************************************************************************************/
//Displays the main menu of the game
void Game_r::displayMainMenu()
{
    //Clearing the scene
    this->clean_scene();

    //Adding background to scene
    this->scene->setBackgroundBrush(QBrush(QPixmap(":/backgrounds/imgs/bg_colorful-brain.png").scaled(this->scene->sceneRect().width(), this->scene->sceneRect().height())));

    //Creating title and adding it to scene
    QGraphicsTextItem *titleText = new QGraphicsTextItem(QString("Memoria Relacional"));
    QFont titleFont("comic sans", 50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos, tyPos);
    this->scene->addItem(titleText);

    //Creating play button, adding it to scene and connecting the signal to slot
    Button *play_button = new Button(QString(":/buttons/imgs/buttons/play_button.png"), QString(":/buttons/imgs/buttons/play_button_active.png"));
    int pbxPos = this->width()/2 - play_button->boundingRect().width()/2;
    int pbyPos = 350;
    play_button->setPos(pbxPos, pbyPos);
    this->scene->addItem(play_button);
    connect(play_button, SIGNAL(clicked()), this, SLOT(start()));

    //Creating quit button, adding it to scene and connecting the signal to slot
    Button *quit_button = new Button(QString(":/buttons/imgs/buttons/quit_button.png"), QString(":/buttons/imgs/buttons/quit_button_active.png"));
    int qbxPos = this->width()/2 - quit_button->boundingRect().width()/2;
    int qbyPos = 450;
    quit_button->setPos(qbxPos, qbyPos);
    this->scene->addItem(quit_button);
    connect(quit_button, SIGNAL(clicked()), this, SLOT(close_game()));
}

/*************************************************************************************/
//Displays restart game scene
void Game_r::displayRestartGame()
{
    //Clearing scene
    this->clean_scene(true);

    //Creating "win" message and adding it to scene
    QGraphicsTextItem *message = new QGraphicsTextItem(QString("¡Ganaste!"));
    QFont messageFont("comic sans", 50);
    message->setFont(messageFont);
    int mxPos = this->width()/2 - message->boundingRect().width()/2;
    int myPos = 150;
    message->setPos(mxPos, myPos);
    this->scene->addItem(message);

    //Creating "accuracy percent" message and adding it to scene
    QGraphicsTextItem *accuracy = new QGraphicsTextItem(QString("Porcentaje de aciertos: ") + QString::number(((qreal)this->relations_found/(qreal)this->tries) * 100) + QString("%"));
    QFont accuracyFont("comic sans", 18);
    accuracy->setFont(accuracyFont);
    int axPos = this->width()/2 - accuracy->boundingRect().width()/2;
    int ayPos = 250;
    accuracy->setPos(axPos, ayPos);
    this->scene->addItem(accuracy);

    //Creating repeat button, adding it to scene and connecting signal and slot
    Button *repeat_button = new Button(QString(":/buttons/imgs/buttons/restart_button.png"), QString(":/buttons/imgs/buttons/restart_button_active.png"));
    int rbxPos = this->width()/2 - repeat_button->boundingRect().width()/2;
    int rbyPos = 350;
    repeat_button->setPos(rbxPos, rbyPos);
    this->scene->addItem(repeat_button);
    connect(repeat_button, SIGNAL(clicked()), this, SLOT(start()));

    //Creating menu button, adding it to scene and connecting signal and slot
    Button *menu_button = new Button(QString(":/buttons/imgs/buttons/menu_button.png"), QString(":/buttons/imgs/buttons/menu_button_active.png"));
    int mbxPos = this->width()/2 - menu_button->boundingRect().width()/2;
    int mbyPos = 450;
    menu_button->setPos(mbxPos, mbyPos);
    this->scene->addItem(menu_button);
    connect(menu_button, SIGNAL(clicked()), this, SLOT(displayMainMenu()));
}


/*************************************************************************************/
//Displays game over scene
void Game_r::displayGameOver()
{
    size_t cards_left = this->deck.get_num_nodes();
    //Clearing deck
    this->deck.clear();

    //Clearing scene
    this->clean_scene(true);

    //Creating "you lose" message and adding it to scene
    QGraphicsTextItem *message = new QGraphicsTextItem(QString("¡Perdiste!"));
    QFont messageFont("comic sans", 50);
    message->setFont(messageFont);
    int mxPos = this->width()/2 - message->boundingRect().width()/2;
    int myPos = 80;
    message->setPos(mxPos, myPos);
    this->scene->addItem(message);

    //Creating "cards left" message and adding it to scene
    QGraphicsTextItem *message2 = new QGraphicsTextItem(QString("¡Quedaron cartas!"));
    QFont message2Font("comic sans", 50);
    message2->setFont(message2Font);
    int m2xPos = this->width()/2 - message2->boundingRect().width()/2;
    int m2yPos = 150;
    message2->setPos(m2xPos, m2yPos);
    this->scene->addItem(message2);

    //Creating "number of cards left" message and adding it to scene
    QGraphicsTextItem *message3 = new QGraphicsTextItem(QString("Cartas en la mesa: ") + QString::number(cards_left) + QString(" de ") + QString::number(this->total_cards));
    QFont message3Font("comic sans", 18);
    message3->setFont(message3Font);
    int m3xPos = this->width()/2 - message3->boundingRect().width()/2;
    int m3yPos = 250;
    message3->setPos(m3xPos, m3yPos);
    this->scene->addItem(message3);

    //Creating repeat button, adding it to scene and connecting signal and slot
    Button *repeat_button = new Button(QString(":/buttons/imgs/buttons/restart_button.png"), QString(":/buttons/imgs/buttons/restart_button_active.png"));
    int rbxPos = this->width()/2 - repeat_button->boundingRect().width()/2;
    int rbyPos = 350;
    repeat_button->setPos(rbxPos, rbyPos);
    this->scene->addItem(repeat_button);
    connect(repeat_button, SIGNAL(clicked()), this, SLOT(start()));

    //Creating menu button, adding it to scene and connecting signal and slot
    Button *menu_button = new Button(QString(":/buttons/imgs/buttons/menu_button.png"), QString(":/buttons/imgs/buttons/menu_button_active.png"));
    int mbxPos = this->width()/2 - menu_button->boundingRect().width()/2;
    int mbyPos = 450;
    menu_button->setPos(mbxPos, mbyPos);
    this->scene->addItem(menu_button);
    connect(menu_button, SIGNAL(clicked()), this, SLOT(displayMainMenu()));
}

/*************************************************************************************/
//Starts the game (cards are arranged randomly every time)
void Game_r::start()
{
    //Setting tries to 0
    this->tries = 0;

    //Setting relations_found to 0
    this->relations_found = 0;

    //Clearing scene and setting background
    this->clean_scene(true);
    this->scene->setBackgroundBrush(QBrush(QImage(":/backgrounds/imgs/bg_puzzle.jpg").scaled(this->scene->sceneRect().width(), this->scene->sceneRect().height())));

    //Loading images names
    size_t pics = 10;
    SLList<QString> *sll_files = new SLList<QString>();
    load_random_pixmaps_from_dir(sll_files, pics, QString(":/cards/rel1/imgs"));
    load_random_pixmaps_from_dir(sll_files, pics, QString(":/cards/rel2/imgs"));
    load_random_pixmaps_from_dir(sll_files, pics, QString(":/cards/rel3/imgs"));
    random_array(sll_files, pics);

    //Setting total cards
    this->total_cards = sll_files->size();

    //Creating random positions matrix
    int random_places_1[5];
    int random_places_2[5];
    random_pos_numbers_array(random_places_1, pics - 5);
    random_pos_numbers_array(random_places_2, pics - 5);

    //Calculating distance between cards
    qreal x_dist = this->scene->width()/SIZE(random_places_1);
    qreal fix_center = (x_dist - QPixmap((*sll_files)[0]).width())/2;

    //Creating cards
    Card *c[pics];

    //Adding images to cards
    for(size_t i = 0; i < SIZE(c); i++)
        c[i] = new Card(QString(":/cards/dorsal/imgs/secret_card.png"), (*sll_files)[i]);

    random_array(c, SIZE(c));

    //Setting cards in position
    for(size_t i = 0; i < SIZE(c); i++)
    {
        if(i < 5)
            c[i]->setPos(random_places_1[i] * x_dist + fix_center, 100);
        else
            c[i]->setPos(random_places_2[i - 5] * x_dist + fix_center, 280);
    }

    //Filling the graph and adding cards to scene
    for(size_t i = 0; i < SIZE(c); i++)
    {
        //Inserting nodes
        this->deck.insert_node(c[i]);
    }

    for(size_t i = 0; i < SIZE(c); i++)
    {
        c[i] = nullptr;
        delete c[i];
    }

    //Creating arcs and adding cards to scene
    this->deck.for_each_node([&](auto node)
                        {
                            this->deck.for_each_node([&](auto node2)
                                                {
                                                    if(node->get_info()->get_name(1).contains("rel1") and node2->get_info()->get_name(1).contains("rel1")
                                                            and node->get_info()->get_name(1) != node2->get_info()->get_name(1))
                                                        this->deck.insert_arc(node, node2, 1);

                                                    else if(node->get_info()->get_name(1).contains("rel2") and node2->get_info()->get_name(1).contains("rel2")
                                                            and node->get_info()->get_name(1) != node2->get_info()->get_name(1))
                                                        this->deck.insert_arc(node, node2, 2);

                                                    else if(node->get_info()->get_name(1).contains("rel3") and node2->get_info()->get_name(1).contains("rel3")
                                                            and node->get_info()->get_name(1) != node2->get_info()->get_name(1))
                                                        this->deck.insert_arc(node, node2, 3);
                                                });
                            //Adding cards to scene
                            this->scene->addItem(node->get_info());
                        });

    //Creating menu button, adding it to scene and connecting signal and slot
    Button *menu_button = new Button(QString(":/buttons/imgs/buttons/menu_button.png"), QString(":/buttons/imgs/buttons/menu_button_active.png"));
    int mbxPos = this->width() - menu_button->boundingRect().width() - 20;
    int mbyPos = 20;
    menu_button->setPos(mbxPos, mbyPos);
    this->scene->addItem(menu_button);
    connect(menu_button, SIGNAL(clicked()), this, SLOT(displayMainMenu()));

    //Creating relate button, adding it to scene and connecting signal and slot
    Button *relate_button = new Button(QString(":/buttons/imgs/buttons/relate_button.png"), QString(":/buttons/imgs/buttons/relate_button_active.png"));
    int rbxPos = this->width()/2 - relate_button->boundingRect().width()/2;
    int rbyPos = this->height() - relate_button->boundingRect().height() - 30;
    relate_button->setPos(rbxPos, rbyPos);
    this->scene->addItem(relate_button);
    connect(relate_button, SIGNAL(clicked()), this, SLOT(compare_cards()));

    //Creating "tries" text and adding it to scene
    this->triesText = new QGraphicsTextItem(QString("Intentos: ") + QString::number(this->tries));
    QFont triesFont("comic sans", 12);
    this->triesText->setFont(triesFont);
    int ttxPos = 20;
    int ttyPos = menu_button->boundingRect().height()/2 - this->triesText->boundingRect().height()/2 + 20;
    this->triesText->setPos(ttxPos, ttyPos);
    this->scene->addItem(triesText);
}

/*************************************************************************************/
//Compares all selected cards if they have a relation
void Game_r::compare_cards()
{
    bool are_related = false;
    //Getting all cards that are selected
    this->cards = this->deck.map_nodes_if<Deck::Node*>([](auto n){ return n; }, [](auto n)
                                                                                    {
                                                                                        return n->get_info()->is_up();
                                                                                    });


    SLList<Deck::Arc*> arcs;
    //Getting adjacent arcs from all selected cards
    for(auto n :  this->cards)
    {
        SLList<Deck::Arc*> adjacent_arcs = this->deck.adjacent_arcs(n);

        for(auto a : adjacent_arcs)
            arcs.append(a);
    }

    if(this->cards.size() > 1)
    {
        this->triesText->setPlainText(QString("Intentos: " + QString::number(++this->tries)));

        if(this->cards.all([](auto c){ return c->get_info()->get_name(1).contains("rel1"); }))
            are_related = true;

        else if(this->cards.all([](auto c){ return c->get_info()->get_name(1).contains("rel2"); }))
            are_related = true;

        else if(this->cards.all([](auto c){ return c->get_info()->get_name(1).contains("rel3"); }))
            are_related = true;


        //If cards are related, change opacity, remove cards from deck and add 1 to pairs_found
        if(are_related)
        {
            //Changing opacity of selected cards
            for(auto n : this->cards)
            {
                n->get_info()->setOpacity(0.4);
                n->get_info()->setEnabled(false);
                this->deck.remove_node(n);
            }

            this->relations_found++;
        }

        //If cards are wrong, wait 0.5 seconds and then hide the cards
        else
        {
            QThread::msleep(500);
            for(auto n : this->cards)
                n->get_info()->hide_card();
        }


        //If there are no more cards, display restart game scene
        if(this->deck.get_num_nodes() == 0)
            this->displayRestartGame();

        else if(this->deck.get_num_arcs() == 0)
            this->displayGameOver();
    }
    else if(this->cards.size() == 1)
        this->cards[0]->get_info()->hide_card();
}

/*************************************************************************************/
//Free memory and close game
void Game_r::close_game()
{
    //Clearing the scene
    this->clean_scene(true);

    //Showing game_select window
    (new game_select())->show();

    //Closing view
    this->close();
}

/*************************************************************************************/
//Private function: Free memory
void Game_r::clean_scene(bool free_memory)
{
    //Removing items froms scene
    if(free_memory)
    {
        this->deck.clear();
        QList<QGraphicsItem*> items = this->scene->items();
        for(auto i: items)
        {
            this->scene->removeItem(i);
            delete i;
        }
    }

    else
    {
        QList<QGraphicsItem*> items = this->scene->items();
        for(auto i: items)
            this->scene->removeItem(i);
    }

    //Clearing the scene
    this->scene->clear();
}
