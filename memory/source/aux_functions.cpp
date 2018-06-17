/**
 * @file aux_functions.cpp
 * @author Angel España - GitHub aespaben
 * @author Patricia Daboin - GitHub apdaboin
 */

#include <headers/aux_functions.h>
void random_pos_numbers_array(int a[], size_t a_size)
{
    srand(time(NULL));
    bool used[a_size];

    for(size_t i = 0; i < a_size; i++)
        used[i] = false;

    int pos;
    for(size_t i = 0; i < a_size; i++)
    {
        pos = rand()%a_size;

        if(used[pos])
        {
            while(used[pos])
                pos = rand()%a_size;
        }
        a[i] = pos;
        used[pos] = true;
    }
}

/*************************************************************************************/
template<typename T>
void random_array(T a[], size_t a_size)
{
    srand(time(NULL));
    bool used[a_size];
    int aux[a_size];
    T b[a_size];

    for(size_t i = 0; i < a_size; i++)
        used[i] = false;

    int pos;
    for(size_t i = 0; i < a_size; i++)
    {
        pos = rand()%a_size;

        if(used[pos])
        {
            while(used[pos])
                pos = rand()%a_size;
        }
        aux[i] = pos;
        used[pos] = true;
    }

    for(size_t i = 0; i < a_size; i++)
        b[i] = a[aux[i]];

    for(size_t i = 0; i < a_size; i++)
        a[i] = b[i];
}

/*************************************************************************************/
void random_array(SLList<QString> *a, size_t a_size)
{
    srand(time(NULL));
    bool used[a_size];
    int aux[a_size];
    SLList<QString> * b = new SLList<QString>();

    for(size_t i = 0; i < a_size; i++)
        used[i] = false;

    int pos;
    for(size_t i = 0; i < a_size; i++)
    {
        pos = rand()%a_size;

        if(used[pos])
        {
            while(used[pos])
                pos = rand()%a_size;
        }
        aux[i] = pos;
        used[pos] = true;
    }

    for(size_t i = 0; i < a_size; i++)
        b->append((*a)[aux[i]]);

    a->swap(*b);
}

/*************************************************************************************/
void random_array(Card *c[],size_t c_size)
{
    srand(time(NULL));
    bool used[c_size];
    int aux[c_size];
    Card *b[c_size];

    for(size_t i = 0; i < c_size; i++)
        used[i] = false;

    int pos;
    for(size_t i = 0; i < c_size; i++)
    {
        pos = rand()%c_size;

        if(used[pos])
        {
            while(used[pos])
                pos = rand()%c_size;
        }
        aux[i] = pos;
        used[pos] = true;
    }

    for(size_t i = 0; i < c_size; i++)
        b[i] = c[aux[i]];

    for(size_t i = 0; i < c_size; i++)
        c[i] = b[i];
}

/*************************************************************************************/
void load_random_pixmaps_from_dir(QPixmap p[], size_t p_size, QString qs_dir)
{
    SLList<QString> *sll_imgs = new SLList<QString>();
    QDirIterator it(qs_dir, QDirIterator::Subdirectories);

    while(it.hasNext())
        sll_imgs->append(it.next());

    random_array(sll_imgs, sll_imgs->size());


    for(size_t i = 0; i < p_size; i++)
        p[i].load((*sll_imgs)[i]);
}

void load_random_pixmaps_from_dir(SLList<QString> *sll_files, size_t l_size, QString qs_dir)
{
    SLList<QString> *sll_imgs = new SLList<QString>();
    QDirIterator it(qs_dir, QDirIterator::Subdirectories);

    size_t images = 0;
    while(it.hasNext())
    {
        sll_imgs->append(it.next());
        images++;
    }

    random_array(sll_imgs, sll_imgs->size());
    if(l_size <= images)
    {
        for(size_t i = 0; i < l_size; i++)
            sll_files->append((*sll_imgs)[i]);
    }

    else
    {
        for(size_t i = 0; i < images; i++)
            sll_files->append((*sll_imgs)[i]);
    }
}
