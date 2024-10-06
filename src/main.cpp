#include <fstream> 
#include <math.h>

int main(int argc, char *argv[])
{
    char file[] = "dataTest", *file2;
    //параметры из первой таблицы
    int a,a2,a3,a4;
    const char *coeff[3] = {"Рейтинг при коэффициенте вида - 1/(L+R)", "Рейтинг при коэффициенте вида - 1/(L*R)", "Рейтинг при коэффициенте вида - 1/L+1/R"};
    double Coefficient(double, double, int);
    if (argc>1)
    {
        file2 = argv[1];
    } else file2 = file;
    

    std::ifstream in(file2, std::ios::in);
    if (!in)
    {
        printf("Файл %s не открыт", file);
        return -1;
    }

    in >> a; in >> a2; in >>a3; in >> a4;
    
    int n2 = a*a2*a3+a*a4, n, x;
    //потенциальный объем программы
    double V = (n2+2)*log2(n2+2);
    //L -, N -, Tk -, r0 -
    double L, N, Tk, t, r0, r;
    char u;
    in >> r0;
    in >> L;
    in >> n;
    //массивы объёмов программ и совершённых в них ошибок
    int volumes[n], errors[n];
    in >> volumes[0];
    for (size_t i = 1; i < n; i++)
    {
        in >> u;
        in >> volumes[i];
    }
    in >> errors[0];
    for (size_t i = 1; i < n; i++)
    {
        in >> u;
        in >> errors[i];
    }
    in >> x;
    
    int B = pow(V, 2)/(3000*L);

    printf("Задание №1 потенциальное число ошибок %d \n", B);

    int i=1, V2, P, B2, k=n2/8;
    //количество разработчиков
    int m = 5;
    // число отлаженных команд в день
    int v = 10;
    
    if (k > 8) {
        i = (int) log2(n2)/3 +1;
        k = n2/8 + n2/64;
    }
    
    N = 220*k + k*log2(k);
    V2 = (int) k*220*log2(48);
    printf("ПС имеет %d уровней и %d модулей. Длина программы %.0f, объём %d байт\n", i, k, N, V2);
    P = 3*N/8;
    Tk = 3*N/(8*m*v);
    B2 = V2/3000;
    printf("Потенциальное число ошибок %d, количество команд ассемблера %d и время программирования %0.1f\n", B2, P, Tk);

    //время наработки на отказ в часах (7 часов рабочий день)
    t = (Tk / (2*log(B2)))*7;
    printf("Время наработки на отказ - %.1f часов \n", t);
    double sumVl, sumErToCof;
    for (size_t j = 1; j < 4; j++)
    {
        r = r0;
        sumVl = 0, sumErToCof=0;
        printf("%s\n", coeff[j-1]);
        for (int i = 0; i < n; i++)
        {
            sumVl += volumes[i];
            if (errors[i] != 0)
            {
                sumErToCof += errors[i]/Coefficient(r, L, j);
            }
            r = r*abs(1+0.001*(sumVl - sumErToCof));
            printf("Рейтинг программиста после написнаия программы №%i - %.3f \n", i+1, abs(r));
        }
        printf("Ожидаемое число ошибок: %.2f\n", Coefficient(r, L, j)*x);
    }
    in.close();
}

double Coefficient(double rating, double l, int i) {
    switch (i)
    {
    case 1:
        return 1/(l+rating);
    case 2:
        return 1/(l*rating);
    case 3:
        return (1/l+1/rating);
    default:
        return 1/(l+rating);
    }
}
