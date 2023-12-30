# Asteroids

Игра про космос, в которой корабль уничтожает астеройды. При столкновении 
с астеройдами корабль уничтожается.

https://github.com/Araime/Asteroids/assets/82653875/d6041447-6f65-42df-abe9-74a24cb894ba

## Обновления

**18.12.2023**  
Проект пересобран на SFML 2.6.1, реорганизация структуры файлов проекта.
Добавлена функция для случайной генерации новых астероидов.

**Update #4.**  
Добавлен таймер возрождения, добавлены жизни корабля. Огромный рефакторинг 
кода всей игры, максимальная инкапсуляция всех функций. Добавлены спрайты 
для состояний игры, музыка для состояний игры. Добавлены разные звуки. 
Множественные правки багов😇.

**Update #5.**  
Рефакторинг кода функций, связанных со смертью и возрождением. Добавление 
здоровья кораблю, теперь не упарывается с одного касания. Правка начальной 
скорости создаваемых астероидов, больше никаких астероидов с нулевой 
скоростью по х или у координате и уж тем более вертящихся на месте.

**Update #6.**  
Заменен фон уровня. Пересборка игровых шрифтов, создан отдельный класс 
шрифтов. Создан новый класс оружия, залп ракет. Создан класс UI, в котором 
отображается уровень здоровья, кол-во жизней, выбранное оружие. Большой 
рефакторинг кода, удаление множества "магических чисел", ни о чем не 
говорящих. Добавлены новые звуки для оружия и меню.

## TO DO:
~~другое оружие/смена оружия,~~  
выпадение PowerUps,  
~~реализовать полноценно игровой единый шрифт,~~  
возможно прокачка уровней (врядли).  

## Установка

### Скачать

VisualStudio должен быть уже установлен.
[Скачать](https://github.com/Araime/Asteroids/archive/master.zip) этот
репозиторий себе на компьютер. В репозиторий входят все необхдимые 
реурсы, а также библиотека SFML.


### Запуск

В папке репозитория открыть файл `Asteroids.sln`, запустить.

## Credits
- Музыка:  
	- `меню` cynicmusic - Enchanted Tiki 86.mp3  
	- `уровень` maxstack - through space.ogg  
	- `конец игры` Alexandr Zhelanov - space.mp3  

- Звуки:  
    - `Лазер` 
		- Kenney - 63 Digital sound effects/laser1.wav  
		- Kenney - 63 Digital sound effects/laser2.wav  
		- Kenney - 63 Digital sound effects/laser3.wav

	- `Ракета`
 		- dklon - Rocket Launch Pack/rocket_launch1.wav  
		- dklon - Rocket Launch Pack/rocket_launch2.wav  
		- dklon - Rocket Launch Pack/rocket_launch3.wav  
		- dklon - Rocket Launch Pack/rocket_launch4.wav  

	- `Смена оружия`
		- Tim Mortimer - 4 sci-fi menu sounds/Flashpoint001a.flac  

	- `Отсчет`
		- legoluft - Krank_sounds/magnet_start.wav  

	- `Взрывы`
		- dklon - Boom Pack 1/boom2.wav  
		- dklon - Boom Pack 1/boom9.wav  

## Цель проекта

Создание игры на C++ с использованием библиотеки SFML.
