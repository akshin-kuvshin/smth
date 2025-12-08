// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>

void render_full(int width, char border_char);
void render_empty(int width, char border_char);
void render_text(int width, char border_char, const std::string& text);

int main() {
	setlocale(LC_ALL, ""); // на моём ПК поддержка русского текста в консоли успешно (почти; см. ниже) включается, но, возможно, на другом ПК придётся написать "ru" вместо ""
	
	int width;
	std::cout << "Ширина кнопки = ";
	std::cin >> width;
	if (width < 3) {
		std::cerr << "[ОШИБКА]: ширина кнопки, равная " << width << ", недопустима, т.к. должна быть хотя бы 3." << std::endl;
		exit(1);
	}

	int height;
	std::cout << "Высота кнопки = ";
	std::cin >> height;
	if (height < 3) {
		std::cerr << "[ОШИБКА]: высота кнопки, равная " << height << ", недопустима, т.к. должна быть хотя бы 3." << std::endl;
		exit(2);
	}

	/* P.S.: ограничения на ширину и высоту кнопки были выбраны мной таким образом, чтобы внутри кнопки всегда
	*  имелось свободное место, куда можно вставить хотя бы одну букву. */

	/* тут, к сожалению, так и не разобрался, как включить поддержку не только вывода русского текста, но и его ввода,
	*  поэтому ограничимся латинскими буквами, цифрами и спец. символами в качестве содержания текста внутри кнопки */
	std::string text;
	std::cout << "Текст на кнопке = ";
	std::cin.ignore();
	std::getline(std::cin, text);
	if ((int)text.length() > width - 2) {
		std::cerr << "[ОШИБКА]: в кнопке с шириной " << width << " невозможно разместить текст длиной " << (int)text.length() << '.' << std::endl;
		exit(3);
	}

	char border_char;
	std::cout << "Символ рамки = ";
	std::cin >> border_char;

	/* Под "округлением вниз", упомянутом в условии, будем понимать то, что строки пронумерованы (начиная с 0)
	*  снизу вверх, столбцы (также начиная с 0) - слева направо, и округление происходит именно внутри данной
	*  нумерации. Иными словами, если кол-во строк чётно, то текст будет расположен в верхней из двух строк
	*  посередине; если чётности ширины и длины текста не совпали, то отступ между текстом и левой границей
	*  рамки будет на 1 меньше аналогичного отступа с правой стороны. */
	int text_row = (height - 1) / 2;
	for (int row = 0; row < height; ++row) {
		if (row == 0 or row == height - 1)
			render_full(width, border_char);
		else if (row == text_row)
			render_text(width, border_char, text);
		else
			render_empty(width, border_char);
	}

	return 0;
}

void render_full(int width, char border_char) {
	while (width--)
		std::cout << border_char;
	std::cout << std::endl;
}

void render_empty(int width, char border_char) {
	width -= 2;
	std::cout << border_char;
	while (width--)
		std::cout << ' ';
	std::cout << border_char << std::endl;
}

void render_text(int width, char border_char, const std::string& text) {
	int margin_left = (width - 2 - (int)text.length()) / 2;
	int margin_right = width - 2 - (int)text.length() - margin_left;
	std::cout << border_char;
	while (margin_left--)
		std::cout << ' ';
	std::cout << text;
	while (margin_right--)
		std::cout << ' ';
	std::cout << border_char << std::endl;
}
