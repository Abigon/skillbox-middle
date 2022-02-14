# SkillboxMiddle
Задания в рамках обучения Skillbox


## MiddleThread1.cpp
Что нужно сделать 
Создать полноценное exe-приложение на основе многопоточности в С++.
Приложение должно выполнять весь жизненный цикл вплоть до закрытия.
Опционально — сделать дополнительное визуальное отображение.

Создайте классическую вилку данных «продюсер — потребитель», где потребитель является отдельным потоком, который формирует выходные данные, удобные для считывания пользователем на консоли, а продюсеры являются отдельными потоками, которые формируют входные данные для потребителя посредством рандома или выборки из пула статических данных.
Обратите внимание! 
Продюсеры генерируют разные псевдоданные из рандома или табличных данных, взятых из общего доступа (например, база данных звёзд). Продюсеры должны генерировать данные с разным интервалом и передавать их потребителю.
Потребитель должен выдать данные пользователю в удобном и читабельном виде (в виде сортировки по нумерации, возрасту, порядку букв по алфавиту и прочее).
Пример: продюсеры генерируют студентов с возрастом, именем и средним баллом успеваемости, а потребитель формирует из этих данных удобную таблицу с сортировкой по успеваемости (в консоли).
Данные должны отображаться в реальном времени.

## MiddleThread2.cpp
Создайте мини-игру на потоках (хард), учитывая:
поток отслеживания инпутов от игрока (вниз, вверх или вправо, вверх);
поток рендера графики с помощью символьных данных (_+-/\{}[]...) в виде дороги (пути) слева направо или снизу вверх и управляемого персонажа и препятствий;
поток обработки препятствий и столкновения игрока.
(референс) Можно сделать игру вроде «Тетриса»: создать две дорожки для автомобилей, где игрок должен перемещаться между дорожками (моментально) для обхода препятствий.

