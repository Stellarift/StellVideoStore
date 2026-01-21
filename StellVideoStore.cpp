#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_FILMS = 100;

struct VideoStore {
    string title;
    string director;
    string genre;
    double rating;
    double price;
};

void showAllRecords(VideoStore films[], int count);
void addRecord(VideoStore films[], int& count);
void searchByTitle(VideoStore films[], int count);
void searchByGenre(VideoStore films[], int count);
void searchByDirector(VideoStore films[], int count);
void mostPopularInGenre(VideoStore films[], int count);
void displayFilm(VideoStore film);

int main() {
    setlocale(LC_ALL, "ru");
    VideoStore videoStore[MAX_FILMS];
    int filmCount = 0;
    int choice;

    do {
        cout << "\nВИДЕОМАГАЗИН\n";
        cout << "1. Показать все фильмы\n";
        cout << "2. Добавить новый фильм\n";
        cout << "3. Поиск по названию\n";
        cout << "4. Поиск по жанру\n";
        cout << "5. Поиск по режиссеру\n";
        cout << "6. Самый популярный фильм в жанре\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            showAllRecords(videoStore, filmCount);
            break;
        case 2:
            addRecord(videoStore, filmCount);
            break;
        case 3:
            searchByTitle(videoStore, filmCount);
            break;
        case 4:
            searchByGenre(videoStore, filmCount);
            break;
        case 5:
            searchByDirector(videoStore, filmCount);
            break;
        case 6:
            mostPopularInGenre(videoStore, filmCount);
            break;
        case 0:
            cout << "Выход из программы...\n";
            break;
        default:
            cout << "Неверный выбор! Попробуйте снова.\n";
        }

    } while (choice != 0);

    return 0;
}

void displayFilm(VideoStore film) {
    cout << left << setw(25) << film.title
        << setw(20) << film.director
        << setw(15) << film.genre
        << setw(10) << fixed << setprecision(1) << film.rating
        << setw(10) << fixed << setprecision(2) << film.price << "$\n";
}

void showAllRecords(VideoStore films[], int count) {
    if (count == 0) {
        cout << "\nВидеомагазин пуст!\n";
        return;
    }

    cout << "\nСПИСОК ВСЕХ ФИЛЬМОВ\n";
    cout << "\n" << string(80, '-') << "\n";
    cout << left << setw(25) << "Название фильма"
        << setw(20) << "Режиссер"
        << setw(15) << "Жанр"
        << setw(10) << "Рейтинг"
        << setw(10) << "Цена\n";
    cout << string(80, '-') << "\n";

    for (int i = 0; i < count; i++) {
        displayFilm(films[i]);
    }

    cout << string(80, '-') << "\n";
    cout << "Всего фильмов: " << count << "\n";
}

void addRecord(VideoStore films[], int& count) {
    if (count >= MAX_FILMS) {
        cout << "\nДостигнуто максимальное количество фильмов!\n";
        return;
    }

    cout << "\nДОБАВЛЕНИЕ НОВОГО ФИЛЬМА\n";

    cout << "Введите название фильма (без пробелов): ";
    cin >> films[count].title;

    cout << "Введите имя режиссера (без пробелов): ";
    cin >> films[count].director;

    cout << "Введите жанр (без пробелов): ";
    cin >> films[count].genre;

    cout << "Введите рейтинг популярности (0-10): ";
    while (!(cin >> films[count].rating) || films[count].rating < 0 || films[count].rating > 10) {
        cout << "Ошибка! Введите число от 0 до 10: ";
        cin.clear(); 
        cin.ignore(1000, '\n');
    }

    cout << "Введите цену диска: ";
    while (!(cin >> films[count].price) || films[count].price <= 0) {
        cout << "Ошибка! Введите положительное число: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    cout << "\nФильм успешно добавлен!\n";
    count++; 
}

void searchByTitle(VideoStore films[], int count) {
    if (count == 0) {
        cout << "\nВидеомагазин пуст!\n";
        return;
    }

    string searchTitle;
    cout << "\nПОИСК ПО НАЗВАНИЮ\n";
    cout << "Введите название фильма для поиска (без пробелов): ";
    cin >> searchTitle;

    bool found = false;

    cout << "\nРезультаты поиска:\n";
    cout << string(80, '-') << "\n";
    cout << left << setw(25) << "Название фильма"
        << setw(20) << "Режиссер"
        << setw(15) << "Жанр"
        << setw(10) << "Рейтинг"
        << setw(10) << "Цена\n";
    cout << string(80, '-') << "\n";

    for (int i = 0; i < count; i++) {
        if (films[i].title == searchTitle) {
            displayFilm(films[i]);
            found = true;
        }
    }

    if (!found) {
        cout << "Фильмы с названием \"" << searchTitle << "\" не найдены.\n";
    }
    cout << string(80, '-') << "\n";
}

void searchByGenre(VideoStore films[], int count) {
    if (count == 0) {
        cout << "\nВидеомагазин пуст!\n";
        return;
    }

    string searchGenre;
    cout << "\nПОИСК ПО ЖАНРУ\n";
    cout << "Введите жанр для поиска (без пробелов): ";
    cin >> searchGenre;

    bool found = false;

    cout << "\nРезультаты поиска:\n";
    cout << string(80, '-') << "\n";
    cout << left << setw(25) << "Название фильма"
        << setw(20) << "Режиссер"
        << setw(15) << "Жанр"
        << setw(10) << "Рейтинг"
        << setw(10) << "Цена\n";
    cout << string(80, '-') << "\n";

    for (int i = 0; i < count; i++) {
        if (films[i].genre == searchGenre) {
            displayFilm(films[i]);
            found = true;
        }
    }

    if (!found) {
        cout << "Фильмы жанра \"" << searchGenre << "\" не найдены.\n";
    }
    cout << string(80, '-') << "\n";
}

void searchByDirector(VideoStore films[], int count) {
    if (count == 0) {
        cout << "\nВидеомагазин пуст!\n";
        return;
    }

    string searchDirector;
    cout << "\nПОИСК ПО РЕЖИССЕРУ\n";
    cout << "Введите имя режиссера для поиска (без пробелов): ";
    cin >> searchDirector;

    bool found = false;

    cout << "\nРезультаты поиска:\n";
    cout << string(80, '-') << "\n";
    cout << left << setw(25) << "Название фильма"
        << setw(20) << "Режиссер"
        << setw(15) << "Жанр"
        << setw(10) << "Рейтинг"
        << setw(10) << "Цена\n";
    cout << string(80, '-') << "\n";

    for (int i = 0; i < count; i++) {
        if (films[i].director == searchDirector) {
            displayFilm(films[i]);
            found = true;
        }
    }

    if (!found) {
        cout << "Фильмы режиссера \"" << searchDirector << "\" не найдены.\n";
    }
    cout << string(80, '-') << "\n";
}

void mostPopularInGenre(VideoStore films[], int count) {
    if (count == 0) {
        cout << "\nВидеомагазин пуст!\n";
        return;
    }

    string searchGenre;
    cout << "\nСАМЫЙ ПОПУЛЯРНЫЙ ФИЛЬМ В ЖАНРЕ\n";
    cout << "Введите жанр (без пробелов): ";
    cin >> searchGenre;

    int maxIndex = -1;
    double maxRating = -1;

    for (int i = 0; i < count; i++) {
        if (films[i].genre == searchGenre) {
            if (films[i].rating > maxRating) {
                maxRating = films[i].rating;
                maxIndex = i;
            }
        }
    }

    if (maxIndex != -1) {
        cout << "\nСамый популярный фильм в жанре \"" << searchGenre << "\":\n";
        cout << string(80, '-') << "\n";
        cout << left << setw(25) << "Название фильма"
            << setw(20) << "Режиссер"
            << setw(15) << "Жанр"
            << setw(10) << "Рейтинг"
            << setw(10) << "Цена\n";
        cout << string(80, '-') << "\n";
        displayFilm(films[maxIndex]);
        cout << string(80, '-') << "\n";
    }
    else {
        cout << "Фильмы жанра \"" << searchGenre << "\" не найдены.\n";
    }
}
