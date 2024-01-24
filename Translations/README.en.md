[![Лицензия: MIT](https://img.shields.io/badge/Лицензия-MIT-green.svg)](https://opensource.org/licenses/MIT)

# Asteroids SFML
Космическая игра, где корабль уничтожает астероиды. При столкновении с астероидами корабль уничтожается.

<kbd>[<img title="Английский (США)" alt="Английский (США)" src="https://cdn.statically.io/gh/hjnilsson/country-flags/master/svg/us.svg" width="22">](Translations/README.en.md)</kbd>
<kbd>[<img title="Русский язык" alt="Русский язык" src="https://cdn.statically.io/gh/hjnilsson/country-flags/master/svg/ru.svg" width="22">](Translations/README.ru.md)</kbd>

https://github.com/Araime/Asteroids/assets/19285919/5b868eb9-550c-4540-a31c-d10c9e01307b

=======================

https://github.com/Araime/Asteroids/assets/82653875/d6041447-6f65-42df-abe9-74a24cb894ba

# ЗАВЕРШЕНО:
~~разное оружие/смена оружия,~~

~~полная реализация единого игрового шрифта,~~

======

~~Поддержка клавиатуры WASD~~

~~+ = Увеличить громкость~~

~~- = Уменьшить громкость~~

~~Numpad8 = Включить/выключить звук~~

~~Ускорение игрока с помощью клавиши Shift и возможность "Токийского дрифта"~~

~~Сигнал тревоги при понижении прочности корабля ниже 50%~~

~~Экран мигает красным/вкл-выкл для имитации красной тревоги~~

~~Таймер, отображающий, сколько времени игрок выжил~~

~~Столкновения астероидов друг с другом для создания более динамичной среды~~

~~Предложения по POWERUP добавлены в ship.cpp~~

## К ВЫПОЛНЕНИЮ:

Падение PowerUp,

возможно, прокачка уровней (маловероятно).

======
ГЛАВНОЕ МЕНЮ на стартовой странице игры, включая ИГРАТЬ, ТИТРЫ, GITHUB, ВЫХОД

- IMGUI чит: предоставляет игроку GUI-опцию для настройки игры во время игры
        * бесконечное HP
        * опция ускорения или замедления атаки
        * использование ускорителей
        * и т.д.
  
После смерти игрока отображается его счет, основанный на количестве уничтоженных астероидов и времени выживания с общим итогом

Добавить поддержку контроллера

======

## Установка

### Скачать исходный код

VisualStudio должен быть уже установлен.

[Скачать - Оригинал](https://github.com/Araime/Asteroids/archive/master.zip) этот репозиторий на ваш компьютер. 
Репозиторий включает все необходимые ресурсы, а также библиотеку SFML.

[Скачать - Вилка](https://github.com/AstroRoost/Contrib_Asteroids_Araime/tree/master) это вилка оригинала: скачайте её на ваш компьютер. 
Репозиторий включает все необходимые ресурсы, а также библиотеку SFML.

### Скачать Отладочную Сборку
[Скачать - Вилка](https://github.com/AstroRoost/Contrib_Asteroids_Araime/tree/master) здесь содержится отладочная сборка, которую можно сразу запустить и играть. Папка и название проекта - 0_DEBUG_BUILD/Asteroids.exe

### Запуск

Откройте файл `Asteroids.sln` в папке репозитория и запустите его.

## Благодарности
- Музыка:  
	- `меню` cynicmusic - Enchanted Tiki 86.mp3
	- `уровень` maxstack - through space.ogg  
	- `конец игры` Alexandr Zhelanov - space.mp3  

- Звуки:
  
    - `Критическое предупреждение игрока` 
		- @Mknai225 - Advanced Digital/Samples/Loops/Bass 160 BPM 2 -> Player_critical sound/Player_critical_damage_warning/Player_critical.wav
   		- https://twitter.com/Mknai225 
  
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

	- `Обратный отсчет`
		- legoluft - Krank_sounds/magnet_start.wav  

	- `Взрывы`
		- dklon - Boom Pack 1/boom2.wav  
		- dklon - Boom Pack 1/boom9.wav
    
 -  Переводы языков:
     - `ChatGPT/Google`
       		- Английский/Русский
-  Образователь по коду/Постоянный обзор на месте:
     - `ChatGPT/C++ Primer Plus (5-е издание)/SFML-Game-Developme-By-Example.pdf`
       		-  [AstroRoost](https://github.com/AstroRoost/Contrib_Asteroids_Araime/tree/master) 
       
-  Участник репозитория:
     - `Текущий репозиторий`
       		- [Araime](https://github.com/AstroRoost/Contrib_Asteroids_Araime/tree/master)
       		- [AstroRoost](https://github.com/AstroRoost/Contrib_Asteroids_Araime/tree/master) 

## Цель проекта

Создание игры на C++ с использованием библиотеки SFML.
