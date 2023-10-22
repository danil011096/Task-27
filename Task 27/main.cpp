#include <iostream>
#include <string>

struct Movie {
	std::string title;
	int year;
	std::string genre;
	unsigned int duration;
	unsigned int price;
};

void print_movie(const Movie& movie) {
	std::cout << "Title: " << movie.title << std::endl;
	std::cout << "Year: " << movie.year << std::endl;
	std::cout << "Genre: " << movie.genre << std::endl;
	std::cout << "Duration: " << movie.duration << " minutes" << std::endl;
	std::cout << "Price: " << movie.price << std::endl;
}

Movie expensive(const Movie* movies, int length) {
	Movie mostExpensive = movies[0];

	for (int i = 1; i < length; ++i) {
		if (movies[i].price > mostExpensive.price) {
			mostExpensive = movies[i];
		}
	}

	return mostExpensive;
}

void update_info(Movie& movie);

int main() {
	setlocale(LC_ALL, "Russian");
	
	Movie hp{
		"Harry Potter and the Sorcerer's Stone",
		2011,
		"Fantasy",
		152,
		30
	};

	print_movie(hp);
	std::cout << "________________________" << std::endl;

	Movie movies[3] = {
		{"The Rum Diary", 2010, "drama", 115, 27},
		{"Glacial period", 2002, "Adventures", 81, 20},
		{"Великий Гэтсби", 2013, "drama", 142, 26}
	};

	Movie MostExpensive = expensive(movies, 3);
	std::cout << "Самый дорогой фильм" << std::endl;
	print_movie(MostExpensive);
	std::cout << "________________________" << std::endl;

    update_info(hp);
    print_movie(hp);

	return 0;
}

void update_info(Movie& movie) {
    int num;
    std::cout << "Выберите, какую информацию о фильме необходимо обновить:" << std::endl;
    std::cout << "1. Название;" << std::endl;
    std::cout << "2. Год выхода;" << std::endl;
    std::cout << "3. Жанр;" << std::endl;
    std::cout << "4. Продолжительность;" << std::endl;
    std::cout << "5. Цена за диск." << std::endl;
    std::cout << "Ввод -> ";
    std::cin >> num;

    switch (num) {
    case 1: {
        std::string new_title;
        std::cout << "Введите новое название фильма:" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, new_title);
        movie.title = new_title;
        break;
    }
    case 2: {
        int new_year;
        std::cout << "Введите новый год выхода фильма:" << std::endl;
        std::cin >> new_year;
        movie.year = new_year;
        break;
    }
    case 3: {
        std::string new_genre;
        std::cout << "Введите новый жанр фильма:" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, new_genre);
        movie.genre = new_genre;
        break;
    }
    case 4: {
        unsigned int new_duration;
        std::cout << "Введите новую продолжительность фильма:" << std::endl;
        std::cin >> new_duration;
        movie.duration = new_duration;
        break;
    }
    case 5: {
        unsigned int new_price;
        std::cout << "Введите новую цену за диск:" << std::endl;
        std::cin >> new_price;
        movie.price = new_price;
        break;
    }
    default:
        std::cout << "Некорректный выбор." << std::endl;
    }

    std::cout << "Информация обновлена." << std::endl;
}
