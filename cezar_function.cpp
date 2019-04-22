#include<cnstr.h>

//Главная функция!

int cezar_algoritm(){

    int choise;
    for (;;) {
    cout << "1 - Зашифровать текст." << endl;
    cout << "2 - Расшифровать текст." << endl;
    cin >> choise;
    if(choise == 1 || choise == 2)
        break;
    else
        cout << "Повторите ввод!" << endl;  //Отчистка экрана! не забыть!
}
    if(choise == 1){

        string msg;
        int max_lng = 0, key;
        cout << "Input your message: ";
        cin.ignore();
        getline(cin, msg); msg += '~';
        srand(time(NULL));
        key = rand_key();
        cout << "Ключ для вашей сесии: " << key << endl;
        max_lng =  find_lng(msg); msg[max_lng] = '\0';
        msg = crypto(msg, max_lng, key, choise);
        cout  << msg << endl;
    }
    else{

        string msg;
        int max_lng = 0, key;
        cout << "Input your message: ";
        cin.ignore();
        getline(cin, msg); msg += '~';
        cout << "Введите ключ дешифровки: ";
        cin >> key;
        max_lng =  find_lng(msg); msg[max_lng] = '\0';
        msg = crypto(msg, max_lng, key, choise);
        cout  << msg << endl;


    }

}






//функция шифрования

string crypto(string msg, int max_lng, int key, int choise){

    if(choise == 1){
    for(int i = 0; i < max_lng; i++){
        int num = convert_C(msg, i);

        if((num + key) < 26){
            num += key;
            msg[i] = convert_A(num);
        }
        else if(num == 101)
            msg[i] = ' ';
        else{
        num = (num + key) - 26;
        msg[i] = convert_A(num);
        }

    }
        }
    if(choise == 2){

        for(int i = 0; i < max_lng; i++){
            int num = convert_C(msg, i);

            if((num - key) < 0){
                num = (num - key) + 26;
                msg[i] = convert_A(num);
            }
            else if(num == 101)
                msg[i] = ' ';
            else{
            num = (num - key);
            msg[i] = convert_A(num);
            }
    }

}
       return msg;
}


//функция генерации ключа

int rand_key(){

    int key;
    for (;;) {
    key = rand() % 26;
        if(key != 0)
            break;
    }
    return key;

}
// Функция нахождения длины массива

int find_lng(string msg){
    int max_lng = 0;
    for(int i = 0; i < 9999999; i++) {
        if(msg[i] == '~')
            break;
        else
            max_lng ++;
    }
    return max_lng;
}

// Функция конвертация чисел в буквы

char convert_A(int num){

    char ret_A;

    if(num == 0)
        ret_A = 'a';
    else if(num == 1)
        ret_A = 'b';
    else if(num == 2)
        ret_A = 'c';
    else if(num == 3)
        ret_A = 'd';
    else if(num == 4)
        ret_A = 'e';
    else if(num == 5)
        ret_A = 'f';
    else if(num == 6)
        ret_A = 'g';
    else if(num == 7)
        ret_A = 'h';
    else if(num == 8)
        ret_A = 'i';
    else if(num == 9)
        ret_A = 'j';
    else if(num == 10)
        ret_A = 'k';
    else if(num == 11)
        ret_A = 'l';
    else if(num == 12)
        ret_A = 'm';
    else if(num == 13)
        ret_A = 'n';
    else if(num == 14)
        ret_A = 'o';
    else if(num == 15)
        ret_A = 'p';
    else if(num == 16)
        ret_A = 'q';
    else if(num == 17)
        ret_A = 'r';
    else if(num == 18)
        ret_A = 's';
    else if(num == 19)
        ret_A = 't';
    else if(num == 20)
        ret_A = 'u';
    else if(num == 21)
        ret_A = 'v';
    else if(num == 22)
        ret_A = 'w';
    else if(num == 23)
        ret_A = 'x';
    else if(num == 24)
        ret_A = 'y';
    else if(num == 25)
            ret_A = 'z';
    else
        cout << "Непредвиденная ошибка!!!" << endl;
    return ret_A;

}


// Функция конвертации букв в цифры


int convert_C(string msg, int i){

    int num = 0;
        if(msg[i] == 'A' || msg[i] == 'a'){
            num = 0;
        }
        else if (msg[i] == 'B' || msg[i] == 'b'){
            num = 1;
        }
        else if (msg[i] == 'C' || msg[i] == 'c'){
            num = 2;
        }
        else if (msg[i] == 'D' || msg[i] == 'd'){
            num = 3;
        }
        else if (msg[i] == 'E' || msg[i] == 'e'){
            num = 4;
        }
        else if (msg[i] == 'F' || msg[i] == 'f'){
            num = 5;
        }
        else if (msg[i] == 'G' || msg[i] == 'g'){
            num = 6;
        }
        else if (msg[i] == 'H' || msg[i] == 'h'){
            num = 7;
        }
        else if (msg[i] == 'I' || msg[i] == 'i'){
            num = 8;
        }
        else if (msg[i] == 'J' || msg[i] == 'j'){
            num = 9;
        }
        else if (msg[i] == 'K' || msg[i] == 'k'){
            num = 10;
        }
        else if (msg[i] == 'L' || msg[i] == 'l'){
            num = 11;
        }
        else if (msg[i] == 'M' || msg[i] == 'm'){
            num = 12;
        }
        else if (msg[i] == 'N' || msg[i] == 'n'){
            num = 13;
        }
        else if (msg[i] == 'O' || msg[i] == 'o'){
            num = 14;
        }
        else if (msg[i] == 'P' || msg[i] == 'p'){
            num = 15;
        }
        else if (msg[i] == 'Q' || msg[i] == 'q'){
            num = 16;
        }
        else if (msg[i] == 'R' || msg[i] == 'r'){
            num = 17;
        }
        else if (msg[i] == 'S' || msg[i] == 's'){
            num = 18;
        }
        else if (msg[i] == 'T' || msg[i] == 't'){
            num = 19;
        }
        else if (msg[i] == 'U' || msg[i] == 'u'){
            num = 20;
        }
        else if (msg[i] == 'V' || msg[i] == 'v'){
            num = 21;
        }
        else if (msg[i] == 'W' || msg[i] == 'w'){
            num = 22;
        }
        else if (msg[i] == 'X' || msg[i] == 'x'){
            num = 23;
        }
        else if (msg[i] == 'Y' || msg[i] == 'y'){
            num = 24;
        }
        else if (msg[i] == 'Z' || msg[i] == 'z'){
            num = 25;
        }
        else
            num = 101;

    return num;
}

