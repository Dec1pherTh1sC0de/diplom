CREATE DATABASE student;

USE student;

CREATE TABLE autorize
(
	Id int,
    Login varchar(40),
    Pass varchar(40)
);

CREATE TABLE specialnost
(
	Id int,
    Specialnost varchar(100)
);

CREATE TABLE obshaga
(
	Id int,
    Adress varchar(100)
);

CREATE TABLE inyaz
(
	Id int,
    Yazik varchar(20)
);

CREATE TABLE formaobuch
(
	Id int,
    Formaobuch varchar(15)
);

CREATE TABLE obooso
(
	Id int,
    Obooso varchar(10)
);

CREATE TABLE kurs
(
	Id int,
    Kurs varchar(10)
);

CREATE TABLE budjet
(
	Id int,
    Budjet varchar(15)
);

CREATE TABLE pol
(
	Id int,
    Pol varchar(10)
);

CREATE TABLE celevik
(
	Id int,
    Celevik varchar(10)
);

CREATE TABLE ycheniki
(
    Id int,
    Specialnost VARCHAR(100),
    Formaobuch VARCHAR(20),
    Obooso VARCHAR (10),
    Kurs varchar(10),
    NumberOfGroup VARCHAR(10),
    Budget VARCHAR (10),
    AdresObshagi VARCHAR (100),
    Pol VARCHAR (10),
    Familia VARCHAR (30),
    Imya VARCHAR (15),
    Otchestvo VARCHAR (30),
    DataRojdenia VARCHAR (15),
    PassData VARCHAR (50),
    SredniyBallPosleSchool VARCHAR (10),
    Inyaz VARCHAR (15),
    MobilniyTel VARCHAR (40),
    Oblast VARCHAR (15),
    Gorod VARCHAR (15),
    Rayon VARCHAR (30),
    AdresProjiv VARCHAR (100),
    SredniyBall VARCHAR (10),
    Celevik VARCHAR (10),
    Roditeli VARCHAR (250),
    MestoRaboty VARCHAR (250),
    Ligoty VARCHAR (250),
    Primechanie VARCHAR (250),
    Otchislen VARCHAR (5),
    DataZachisleniya VARCHAR (20),
    DataOtchislenya VARCHAR (20)
);

CREATE TABLE kontengent
(
Id int,
VsegoGirl VARCHAR (10),
VsegoBoy VARCHAR (10),
Vsego VARCHAR (10),
Platniki VARCHAR (10),
Cheleviki VARCHAR (10),
Budjetniki VARCHAR (10)
);

CREATE TABLE gruppy
(
Id int,
Gruppa VARCHAR (10),
Kurator VARCHAR (50),
NomerCuratora VARCHAR (20),
Starosta VARCHAR (50),
NomerStarosty VARCHAR (20)
);

INSERT autorize (Id, Login, Pass) 
VALUES
(0,'19df4fbc3a','19df4fbc3a');

INSERT inyaz (Id, Yazik) 
VALUES
(0,''),
(1,'Английский'),
(2,'Немецкий'),
(3,'Французский');

INSERT obshaga (Id, Adress) 
VALUES
(0,''),
(1,'г.Пинск, ул. Партизанская, 13.'),
(2,'г.Пинск, ул. Кирова, 34.');

INSERT budjet (Id, Budjet) 
VALUES
(0,''),
(1,'Бюджет'),
(2,'Комерч');

INSERT celevik (Id, Celevik) 
VALUES
(0,''),
(1,'Да'),
(2,'Нет');

INSERT formaobuch (Id, Formaobuch) 
VALUES
(0,''),
(1,'ДФО'),
(2,'ЗФО');

INSERT kurs (Id, Kurs) 
VALUES
(0,null),
(1,'1'),
(2,'2'),
(3,'3'),
(4,'4');

INSERT pol (Id, Pol) 
VALUES
(0,''),
(1,'М'),
(2,'Ж');

INSERT obooso (Id, Obooso) 
VALUES
(0,''),
(1,'ОБО'),
(2,'ОСО');

INSERT specialnost (Id, Specialnost) 
VALUES
(0, ''),
(1,'Мелиорация и водное хозяйство'),
(2, 'Техническое обеспечение мелиоративных и водохозяйственных работ'),
(3, 'Ремонтно-обслуживающее производство в сельском хозяйстве'),
(4, 'Промышленное и гражданское строительство'),
(5, 'Строительство дорог и транспортных объектов');
