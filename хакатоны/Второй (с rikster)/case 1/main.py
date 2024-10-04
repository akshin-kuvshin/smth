#   /-------------------------------------------\
#   |  made by Danila "akshin_" Aksionov,       |
#   |       by Danial "rikster" Seit.           |
#   |___________________________________________|
#
# Bot's username: @hackathon_congratbot


from telebot import *
from json    import *



def is_date_valid(date_str):
    try:
        date = datetime.strptime(date_str, "%d/%m/%Y")
        current_date = datetime.now()
        return date <= current_date
    except ValueError:
        return False



default_congrat_text = 'Отбросив дела, спешу поздравить тебя, {}, с Днём Рождения! Хочу с тобой сегодня, проваляться до обеда и забыв одеть одежду простоять весь день у плиты, готовя ужин при свечах. И как два, опьянённых вином, идиота, до утра протанцевать, забыв о грядущих заботах. Зайчик, я люблю тебя. ❤️'



bot = TeleBot('6877085541:AAHb4-N-vxQrF_dBE3AeadhMxWaAbn5QEro')

@bot.message_handler(content_types = ['text'])
def get_text_message(message):
    if message.text.lower() in ['/h', 'help', '/help', 'start', '/start']:
        bot_help(message)
    elif message.text.lower() in ['/m', 'menu', '/menu']:
        bot_menu(message)
    else:
        help_keyboard = types.InlineKeyboardMarkup()
        help_key = types.InlineKeyboardButton('Помощь 🆘', callback_data = 'help')
        help_keyboard.add(help_key)
        bot.send_message(message.chat.id, 'Не понимаю тебя, мой друг 😞\nОбратись за помощью:', reply_markup = help_keyboard)    

@bot.callback_query_handler(func = lambda call: True)
def get_clicked_button(call):
    if call.data == 'help':
        bot_help(call.message)
    elif call.data == 'menu':
        bot_menu(call.message)
    elif call.data == 'check_all':
        bot_check_all(call.message)
    elif call.data == 'add':
        bot_add(call.message)
    elif call.data == 'delete':
        bot_delete(call.message)
    elif call.data == 'check_today':
        bot_check_today(call.message)
    elif call.data == 'change_congrat_text':
        bot_change_congrat_text(call.message)    

def bot_help(message):
    menu_keyboard = types.InlineKeyboardMarkup()
    menu_key = types.InlineKeyboardButton('Меню 📚', callback_data = 'menu')
    menu_keyboard.add(menu_key)
    bot.send_message(message.chat.id, f"Добро пожаловать, {message.chat.first_name}{' ' + message.chat.last_name if message.chat.last_name else ''}! 👋\nТы обратился к CongratBot\'у - к боту, который будет напоминать тебе поздравлять с днём рождения твоих друзей и родных!)\n\nДля дальнейшей работы зайди в меню:", reply_markup = menu_keyboard)    

def bot_menu(message):
    actions_keyboard = types.InlineKeyboardMarkup()

    check_all_button = types.InlineKeyboardButton('Посмотреть все ДР 👀', callback_data = 'check_all')
    add_button = types.InlineKeyboardButton('Добавить новое ДР 📌', callback_data = 'add')
    delete_button = types.InlineKeyboardButton('Удалить старое ДР 🧨', callback_data = 'delete')
    check_today_button = types.InlineKeyboardButton('Есть ли ДР сегодня? 🧐', callback_data = 'check_today')
    change_congrat_text_button = types.InlineKeyboardButton('Изменить текст поздравления ✏️', callback_data = 'change_congrat_text')

    actions_keyboard.add(check_all_button)
    actions_keyboard.add(add_button)
    actions_keyboard.add(delete_button)
    actions_keyboard.add(check_today_button)
    actions_keyboard.add(change_congrat_text_button)
    
    bot.send_message(message.chat.id, 'Выбери необходимое тебе действие из списка:', reply_markup = actions_keyboard)    

def bot_check_all(message):
    with open('birthdays.json', 'r') as f:
        birthdays = load(f)
    
    chat_id = str(message.chat.id)
    if chat_id not in birthdays.keys():
        bot.send_message(message.chat.id, 'Извините, но Вы ещё не добавили ни одного дня рождения... 😞\n\nЧтобы исправить это, выберите пункт \"Добавить новое ДР\" в меню.')
    else:
        birthdays_string = ''
        ind = 1
        for name, day, month, year in birthdays[chat_id]:
            birthdays_string += f'{ind}) {name} - {day}/{month}/{year}\n'
            ind += 1
        bot.send_message(message.chat.id, 'Вот список всех добавленных Вами дней рождения:\n\n' + birthdays_string)
    bot_menu(message)

def bot_add(message):
    bot.send_message(message.chat.id, 'Чтобы добавить новое ДР, напишите сначала имя человека (оно может состоять из нескольких слов) и день его рождения в формате DD/MM/YYYY.\n\nP.S.: если Вы передумали добавлять новое ДР, напишите \"Отмена\".')    
    bot.register_next_step_handler(message, get_new_birthday)

def get_new_birthday(message):
    if message.text.strip().lower() == 'отмена':        
        bot_menu(message)
    else:
        birthday_text = message.text.split()
        
        name = ' '.join(birthday_text[: -1])
        name = name if name else 'noname'
        date = birthday_text[-1]

        if is_date_valid(date):
            date_arr = date.split('/')

            day = date_arr[0]
            month = date_arr[1]
            year = date_arr[2]

            with open('birthdays.json', 'r') as f:
                birthdays = load(f)
            
            chat_id = str(message.chat.id)
            if chat_id not in birthdays.keys():
                birthdays[chat_id] = []
            
            birthdays[chat_id].append((name, day, month, year))
            with open('birthdays.json', 'w') as f:
                dump(birthdays, f)

            bot.send_message(message.chat.id, f'ДР нового человека по имени \"{name}\" успешно добавлено! 😎')            
            bot_menu(message)
        else:
            bot.send_message(message.chat.id, 'Извините, но Ваша дата - инвалид... ♿\nПопробуйте ещё раз!\n\nP.S.: если Вы передумали добавлять новое ДР, напишите \"Отмена\".')            
            bot.register_next_step_handler(message, get_new_birthday)

def bot_delete(message):
    with open('birthdays.json', 'r') as f:
        birthdays = load(f)
    
    chat_id = str(message.chat.id)
    if chat_id not in birthdays.keys():
        bot.send_message(message.chat.id, 'Извините, но Вы ещё не добавили ни одного дня рождения, чтобы удалить его... 😞\n\nЧтобы исправить это, выберите пункт \"Добавить новое ДР\" в меню.')
        bot_menu(message)
    elif len(birthdays[chat_id]) == 0:
        bot.send_message(message.chat.id, 'Извините, но Вы ещё не добавили ни одного дня рождения, чтобы удалить его... 😞\n\nЧтобы исправить это, выберите пункт \"Добавить новое ДР\" в меню.')
        bot_menu(message)
    else:
        birthdays_string = ''
        ind = 1
        for name, day, month, year in birthdays[chat_id]:
            birthdays_string += f'{ind}) {name} - {day}/{month}/{year}\n'
            ind += 1
        bot.send_message(message.chat.id, 'Вот список всех добавленных Вами дней рождения:\n\n' + birthdays_string + '\nВведите номер удаляемого.\n\nP.S.: если Вы передумали удалять ДР, напишите \"Отмена\".')
        bot.register_next_step_handler(message, delete_old_birthday)

def delete_old_birthday(message):
    if message.text.strip().lower() == 'отмена':        
        bot_menu(message)
    else:
        try:
            ind = int(message.text) - 1
            chat_id = str(message.chat.id)
            with open('birthdays.json', 'r') as f:
                birthdays = load(f)
            if 0 <= ind < len(birthdays[chat_id]):
                name, day, month, year = birthdays[chat_id][ind]
                birthdays[chat_id].pop(ind)
                with open('birthdays.json', 'w') as f:
                    dump(birthdays, f)
                bot.send_message(message.chat.id, f'ДР человека по имени \"{name}\" успешно удалено! 😎')
                bot_menu(message)
            else:
                bot.send_message(message.chat.id, 'Нет такого номера, блин( 😞\nПопробуй ещё раз.\n\nP.S.: если Вы передумали удалять ДР, напишите \"Отмена\".')
                bot.register_next_step_handler(message, delete_old_birthday)
        except:
            bot.send_message(message.chat.id, 'Цифрами, пожалуйста. 🥺🙏\nПопробуй ещё раз.\n\nP.S.: если Вы передумали удалять ДР, напишите \"Отмена\".')
            bot.register_next_step_handler(message, delete_old_birthday)


def bot_check_today(message):
    with open('birthdays.json', 'r') as f:
        birthdays = load(f)
    with open('congrat_texts.json', 'r') as f:
        texts = load(f)
    
    user_id = str(message.chat.id)

    if user_id not in birthdays.keys():
        bot.send_message(message.chat.id, 'Извините, но Вы ещё не добавили ни одного дня рождения.. 😞\n\nЧтобы исправить это, выберите пункт \"Добавить новое ДР\" в меню.')
    else:
        if user_id not in texts.keys():
            texts[user_id] = default_congrat_text
            with open('birthdays.json', 'w') as f:
                dump(birthdays, f)
        
        birthday_message_text = ''
        today = datetime.now()

        for name, day, month, year in birthdays[user_id]:
            if int(day) == today.day and int(month) == today.month:
                birthday_message_text += f'\n\n{name}! 🎂\nВот его поздравительный текст:\n\"{texts[user_id].format(name)}\"'
        
        if birthday_message_text == '':
            bot.send_message(message.chat.id, 'К сожалению, сегодня некого поздравлять, ведь сегодня нет ни одного дня рождения... 😞')
        else:
            bot.send_message(message.chat.id, 'Сегодня день рождения у... (*барабанная дробь*) 🥁' + birthday_message_text + '\n\nПоздравляем именинников!!! Ура! 🎉')
    
    bot_menu(message)

def bot_change_congrat_text(message):
    with open('congrat_texts.json', 'r') as f:
        texts = load(f)
    
    chat_id = str(message.chat.id)
    if chat_id not in texts.keys():
        texts[chat_id] = default_congrat_text
    
    bot.send_message(message.chat.id, f'Ваш текущий поздравительный текст:\n\n\"{texts[chat_id]}\"\n\nВведите новый поздравительный текст, заменив в нём имя поздравляемого человека на пару фигурных скобочек (вот такие два символа -> ' + r'{}):' + '\n\nP.S.: если Вы передумали менять свой поздравительный текст, напишите \"Отмена\".')

    with open('congrat_texts.json', 'w') as f:
        dump(texts, f)

    bot.register_next_step_handler(message, get_new_congrat_text)

def get_new_congrat_text(message):
    chat_id = str(message.chat.id)
    new_text = message.text

    if new_text.strip().lower() == 'отмена':        
        bot_menu(message)
    elif r'{}' in new_text:
        with open('congrat_texts.json', 'r') as f:
            texts = load(f)
        texts[chat_id] = new_text
        with open('congrat_texts.json', 'w') as f:
            dump(texts, f)
        bot.send_message(message.chat.id, 'Ура! Ваш поздравительный текст успешно обновлён! 😎')        
        bot_menu(message)
    else:
        bot.send_message(message.chat.id, r'Извините, но Вы ввели некорректный поздравительный текст - в нём нет символов {}. 😞 Попробуйте ещё раз.' + '\n\nP.S.: если Вы передумали менять свой поздравительный текст, напишите \"Отмена\".' + '\n\n:(')        
        bot.register_next_step_handler(message, get_new_congrat_text)

while True:
    bot.polling(none_stop = True, interval = 0, timeout = 1000000)
