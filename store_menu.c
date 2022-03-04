#include <stdio.h>
#include <ctype.h>

#define ARTICH 2.05            //Цена артишока за фунт
#define BEET 1.15              //Цена свеклы за фунт
#define CARROT 1.09            //Цена моркови за фунт
#define DISCOUNT 5.00          //Процент скидки за заказ на сумму выше 100$
#define AMOUNT 100.00          //Сумма необходимая для получения скидки
#define BORDER 5.00            //первая граница веса в фунтах
#define BORDER_UP 20.00        //Вторая граница веса в фунтах
#define DELIV 6.50             //Стоимость доставки весом ниже или равную 5 фунтам
#define DELIV_UP 14.00         //Стоимость доставки весом от 5 до 20 фунтов
#define DELIV_UN_BOR 0.50      //Стоимость доставки каждого фунта свыше 20 уже имеющихся

void interface(void);          //Функция отображает интерфейс программы

int main(void)
{
    int ch;
    float weight, amo_weight, weight_art, weight_beet, weight_car;
    float price, price_art, price_beet, price_car;
    float price_dis, amo_price, price_del;
    float disc, amo_disc;
    int choice;

    amo_weight = 0;
    price = 0;
    amo_price = 0;
    price_art = 0;
    price_beet = 0;
    price_car = 0;
    disc = 0;
    amo_disc = 0;
    weight_art = 0;
    weight_beet = 0;
    weight_car = 0;

    interface();

    scanf("%d", &ch);

    while(ch > 0 && ch < 4)
    {
        switch(ch)
        {
            case 1:     //Вычисляем стоимость артишока
              printf("Укажите вес в фунтах:\n");

              scanf("%f", &weight);

              price = weight * ARTICH;
              weight_art = weight_art + weight;
              amo_weight = amo_weight + weight;
              price_art = price_art + price;

              break;

            case 2:     //Вычисляем стоимость свеклы
              printf("Укажите вес в фунтах:\n");

              scanf("%f", &weight);

              price = weight * BEET;
              weight_beet = weight_beet + weight;
              amo_weight = amo_weight + weight;
              price_beet = price_beet + price;

              break;

            case 3:     //Вычисляем стоимость моркови
              printf("Укажите вес в фунтах:\n");

              scanf("%f", &weight);

              price = weight * CARROT;
              weight_car = weight_car + weight;
              amo_weight = amo_weight + weight;
              price_car = price_car + price;

              break;
        }

        printf("\n");

        puts("___________________________________________");
        puts("Сейчас заказано:");
        printf("Артишока: %.3lf фут.\n", weight_art);
        printf("Свеклы: %.3lf фут.\n", weight_beet);
        printf("Моркови: %.3lf фут.\n", weight_car);
        puts("___________________________________________");

        interface();
        scanf("%d", &ch);
    }

    amo_price = price_art + price_beet + price_car;

    if(amo_price >= AMOUNT)
    {
      disc = amo_price * DISCOUNT / 100;
      amo_price = amo_price - disc;
    }

    if(amo_weight <= BORDER)
    {
      price_del = amo_weight * DELIV;
    }

    else if(amo_weight >= BORDER && amo_weight <= BORDER_UP)
    {
      price_del = amo_weight * DELIV_UP;
    }

    else if(amo_weight > BORDER_UP)
    {
      price_del = (BORDER_UP * DELIV_UP) + ((amo_weight - BORDER_UP) * DELIV_UN_BOR);
    }

    else
      price_del = 0;

    printf("\n");
    printf("Общая информация по вашему заказу:\n");
    printf("\n");
    if(price_art > 0)
    {
      printf("Стоимость фунта артишока = %.3f$\n", ARTICH);
      printf("Всего заказано %.3f фунтов артишока.\n", weight_art);
      printf("Стоимость заказанного артишока = %.3f$\n", price_art);
      printf("\n");
    }

    if(price_beet > 0)
    {
      printf("Стоимость фунта свеклы = %.3f$\n", BEET);
      printf("Всего заказано %.3f фунтов свеклы.\n", weight_beet);
      printf("Стоимость заказнной свеклы = %.3f$\n", price_beet);
      printf("\n");
    }

    if(price_car > 0)
    {
      printf("Стоимость фунта моркови = %.3f$\n", CARROT);
      printf("Всего заказано %.3f фунтов моркови.\n", weight_car);
      printf("Стоимость заказанной моркови = %.3f$\n", price_car);
      printf("\n");
    }

    printf("\n");
    printf("Всего заказано %.3f фунтов(а).\n", amo_weight);
    printf("Общая стоимость заказанных овощей = %.3f$\n", amo_price);
    printf("Скидка = %.3f$\n", disc);
    printf("Затраты на доставку = %.3f$\n", price_del);
    printf("Общая стоимость всего заказа = %.3f$\n", amo_price + price_del);


    return 0;
}

void interface(void)
{
    printf("Выберете товар:\n");
    printf("1. - артишоки         2. - морковь\n");
    printf("3. - свекла\n");
    printf("4. - ВЫХОД\n");
}