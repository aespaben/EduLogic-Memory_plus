/**
 * @file game_c.cpp
 * @author Angel España - GitHub aespaben
 * @author Patricia Daboin - GitHub apdaboin
 */

#include "headers/game_c.h"
Game_c::Game_c(QGraphicsView* parent): QGraphicsView(parent)
{
    //Counting available cards
    this->total_cards = 0;

    QDirIterator it(":/cards/front/imgs", QDirIterator::Subdirectories);

    while(it.hasNext())
    {
        it.next();
        this->total_cards++;
    }

    //Creating scene
    this->scene = new QGraphicsScene();

    //Disabling scroll bars (view)
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //Setting fixed size (view)
    setFixedSize(800,600);

    //Setting view name and icon
    setWindowTitle(QString("Memoria Convencional"));
    setWindowIcon(QIcon("://imgs/colorful-brain+.png"));

    //Centering the window
    QRect rect = QApplication::desktop()->screenGeometry();
    this->move(rect.width()/2 - this->width()/2, rect.height()/2 - this->height()/2);

    //Setting scene rect size
    this->scene->setSceneRect(0,0,800,600);

    //Setting scene to view
    setScene(scene);

    //Creating timer
    this->timer = new QTimer();
}

/*************************************************************************************/
//Class destructor
Game_c::~Game_c()
{
    //Clearing the scene
    this->clean_scene(true);

    //Deleting scene
    delete this->scene;

    //Deleting timer
    delete this->timer;
}

/*************************************************************************************/
//Displays the main menu of the game
void Game_c::displayMainMenu()
{
    //Clearing the scene
    this->clean_scene();

    //Adding background to scene
    this->scene->setBackgroundBrush(QBrush(QPixmap(":/backgrounds/imgs/bg_colorful-brain.png").scaled(this->scene->sceneRect().width(), this->scene->sceneRect().height())));

    //Creating title and adding it to scene
    QGraphicsTextItem *titleText = new QGraphicsTextItem(QString("Memoria Convencional"));
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
    connect(play_button, SIGNAL(clicked()), this, SLOT(difficultySelection()));

    //Creating quit button, adding it to scene and connecting the signal to slot
    Button *quit_button = new Button(QString(":/buttons/imgs/buttons/quit_button.png"), QString(":/buttons/imgs/buttons/quit_button_active.png"));
    int qbxPos = this->width()/2 - quit_button->boundingRect().width()/2;
    int qbyPos = 450;
    quit_button->setPos(qbxPos, qbyPos);
    this->scene->addItem(quit_button);
    connect(quit_button, SIGNAL(clicked()), this, SLOT(close_game()));
}

/*************************************************************************************/
//Displays difficulty selection sreen
void Game_c::difficultySelection()
{
    //Clearing the scene
    this->clean_scene();

    //Adding background to scene
    this->scene->setBackgroundBrush(QBrush(QPixmap(":/backgrounds/imgs/bg_colorful-brain.png").scaled(this->scene->sceneRect().width(), this->scene->sceneRect().height())));

    //Creating title and adding it to scene
    QGraphicsTextItem *titleText = new QGraphicsTextItem(QString("Elige tu nivel de dificultad"));
    QFont titleFont("comic sans", 30);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos, tyPos);
    this->scene->addItem(titleText);

    //Creating easy button, adding it to scene and connecting the signal to slot
    Button *easy_button = new Button(QString(":/buttons/imgs/buttons/easy_button.png"), QString(":/buttons/imgs/buttons/easy_button_active.png"));
    int ebxPos = titleText->x() - easy_button->boundingRect().width()/2;
    int ebyPos = 350;
    easy_button->setPos(ebxPos, ebyPos);
    this->scene->addItem(easy_button);
    connect(easy_button, SIGNAL(clicked()), this, SLOT(easy()));

    //Creating medium button, adding it to scene and connecting the signal to slot
    Button *medium_button = new Button(QString(":/buttons/imgs/buttons/medium_button.png"), QString(":/buttons/imgs/buttons/medium_button_active.png"));
    int mbxPos = titleText->x() + titleText->boundingRect().width()/2 - medium_button->boundingRect().width()/2;
    int mbyPos = 350;
    medium_button->setPos(mbxPos, mbyPos);
    this->scene->addItem(medium_button);
    connect(medium_button, SIGNAL(clicked()), this, SLOT(medium()));

    //Creating hard button, adding it to scene and connecting the signal to slot
    Button *hard_button = new Button(QString(":/buttons/imgs/buttons/hard_button.png"), QString(":/buttons/imgs/buttons/hard_button_active.png"));
    int hbxPos = titleText->x() + titleText->boundingRect().width() - easy_button->boundingRect().width()/2;
    int hbyPos = 350;
    hard_button->setPos(hbxPos, hbyPos);
    this->scene->addItem(hard_button);
    connect(hard_button, SIGNAL(clicked()), this, SLOT(hard()));

    //Creating menu button, adding it to scene and connecting the signal to slot
    Button *menu_button = new Button(QString(":/buttons/imgs/buttons/menu_button.png"), QString(":/buttons/imgs/buttons/menu_button_active.png"));
    int mnbxPos = this->width()/2 - menu_button->boundingRect().width()/2;
    int mnbyPos = this->height() - menu_button->boundingRect().height() - 20;
    menu_button->setPos(mnbxPos, mnbyPos);
    this->scene->addItem(menu_button);
    connect(menu_button, SIGNAL(clicked()), this, SLOT(displayMainMenu()));
}

/*************************************************************************************/
//Displays restart game scene
void Game_c::displayRestartGame()
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
    QGraphicsTextItem *accuracy = new QGraphicsTextItem(QString("Porcentaje de aciertos: ") + QString::number(((qreal)this->pairs_found/(qreal)this->tries) * 100) + QString("%"));
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
//Starts the game (cards are arranged randomly every time)
void Game_c::start()
{
    //Setting tries to 0
    this->tries = 0;

    //Setting pairs_found to 0
    this->pairs_found = 0;

    //Clearing scene
    this->clean_scene(true);

    this->scene->setBackgroundBrush(QBrush(QImage(":/backgrounds/imgs/bg_puzzle.jpg").scaled(this->scene->sceneRect().width(), this->scene->sceneRect().height())));
    //Loading images
    size_t pics = this->difficulty;
    SLList<QString> *sll_files = new SLList<QString>();

    if(pics > 2 and pics <= this->total_cards)
        load_random_pixmaps_from_dir(sll_files, pics, QString(":/cards/front/imgs"));
    else if(pics < 2)
    {
        load_random_pixmaps_from_dir(sll_files, 3, QString(":/cards/front/imgs"));
        pics = 3;
    }
    else
    {
        load_random_pixmaps_from_dir(sll_files, this->total_cards, QString(":/cards/front/imgs"));
        pics = this->total_cards;
    }

    //Creating random positions matrix
    int random_places_1[pics];
    int random_places_2[pics];

    random_pos_numbers_array(random_places_1, SIZE(random_places_1));
    random_pos_numbers_array(random_places_2, SIZE(random_places_2));

    //Calculating distance between cards
    qreal x_dist = this->scene->width()/SIZE(random_places_1);
    qreal fix_center = (x_dist - QPixmap((*sll_files)[0]).width())/2;

    //Creating cards
    Card *c[pics*2];
    //Adding images to cards
    for(size_t i = 0; i < SIZE(c); i++)
    {
        int j = i;
        if(i >= SIZE(c)/2)
            j -= SIZE(c)/2;

        //Adding images to cards
        c[i] = new Card(QString(":/cards/dorsal/imgs/secret_card.png"), (*sll_files)[j]);
    }

    random_array(c, SIZE(c));
    //Setting cards in position
    for(size_t i = 0; i < SIZE(c); i++)
    {
        int j = i;

        if(i >= SIZE(c)/2)
            j -= SIZE(c)/2;

        if(i >= SIZE(c)/2)
            c[i]->setPos(random_places_2[j] * x_dist + fix_center, 350);

        else
            c[i]->setPos(random_places_1[j] * x_dist + fix_center, 100);
    }

    //Filling the graph and adding cards to scene
    for(size_t i = 0; i < SIZE(c)/2; i++)
    {
        //Inserting nodes
        this->deck.insert_node(c[i]);
        this->deck.insert_node(c[i + SIZE(c)/2]);
    }

    //Creating arcs and adding cards to scene
    this->deck.for_each_node([&](auto node)
                        {
                            this->deck.for_each_node([&](auto node2)
                                                {
                                                    if(node->get_info()->get_name(1) == node2->get_info()->get_name(1) and
                                                    not this->deck.exists_adjacent_arc(node, [](auto a){ return a != nullptr;}))
                                                        this->deck.insert_arc(node, node2);
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

    //Creating "tries" text and adding it to scene
    this->triesText = new QGraphicsTextItem(QString("Intentos: ") + QString::number(this->tries));
    QFont triesFont("comic sans", 12);
    this->triesText->setFont(triesFont);
    int ttxPos = 20;
    int ttyPos = menu_button->boundingRect().height()/2 - this->triesText->boundingRect().height()/2 + 20;
    this->triesText->setPos(ttxPos, ttyPos);
    this->scene->addItem(triesText);

    //Connecting timer to compare_cards()
    connect(timer, SIGNAL(timeout()), this, SLOT(compare_cards()));

    //Start timer
    timer->start();
}

/*************************************************************************************/
//Compares two cards if they are up
void Game_c::compare_cards()
{
    //Getting all cards that are up
    this->cards = this->deck.map_nodes_if<Deck::Node*>([](auto n){ return n; }, [](auto n){ return n->get_info()->is_up(); });

    //Flipping cards if are more than 2
    if(this->cards.size() > 2)
        for(auto n : cards)
            n->get_info()->hide_card();

    //Comparing cards if 2 of them are up
    if(this->cards.size() == 2)
    {
        Deck::Node* card1 = cards[0];
        Deck::Node* card2 = cards[1];

        this->triesText->setPlainText(QString("Intentos: " + QString::number(++this->tries)));

        //If cards are equal, change opacity, selected cards, remove cards from deck and add 1 to pairs_found
        if(this->deck.map_adjacent_arcs<Deck::Arc*>(card1, [](auto a){ return a; }).get_first()->get_connected_node(card1)->get_info()->get_name(1) == card2->get_info()->get_name(1))
        {
            //Changing opacity of selected identical cards
            card1->get_info()->setOpacity(0.6);
            card2->get_info()->setOpacity(0.6);

            //Disabling selected identical cards
            card1->get_info()->setEnabled(false);
            card2->get_info()->setEnabled(false);

            //Removing cards from the deck
            this->deck.remove_node(card1);
            this->deck.remove_node(card2);

            this->pairs_found++;
        }
        //If cards are diferent, wait 0.5 seconds and then hide the cards
        else
        {
            QThread::msleep(500);
            for(auto n : cards)
                n->get_info()->hide_card();
        }
    }

    //If there are no more cards, stop timer and then display restart game scene
    if(this->deck.get_num_nodes() == 0)
    {
        this->timer->stop();
        this->displayRestartGame();
    }
}

/*************************************************************************************/
//Free memory and close game
void Game_c::close_game()
{
    this->clean_scene(true);

    //Showing game_select window
    (new game_select())->show();

    //Closing view
    this->close();
}

/*************************************************************************************/
//Private function: Free memory
void Game_c::clean_scene(bool free_memory)
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

/*************************************************************************************/
void Game_c::easy()
{
    this->difficulty = 3;
    this->start();
}

/*************************************************************************************/
void Game_c::medium()
{
    this->difficulty = 5;
    this->start();
}

/*************************************************************************************/
void Game_c::hard()
{
    this->difficulty = 7;
    this->start();
}
