interface ICar {
    id: number;
    gos_number: string;
    mark: string;
    vloume_engine: number;
    max_velocity: number;
    passenger_places: number;
}

class CarPark {
    private cars: Car[] = [];

    addCar(car: Car) {
        this.cars.push(car);
    }

    // Если true - сортируем по скорости, если false - по id
    sortCars(byVelocity: boolean) {
        this.cars.sort((a, b) => {
            return byVelocity ? b.max_velocity - a.max_velocity : a.id - b.id;
        });
    }

    printCars() {
        this.cars.forEach(car => {
            console.log(`id: ${car.id}, Гос. номер: ${car.gos_number}, Марка: ${car.mark}, Объем двигателя: ${car.vloume_engine}, Макс. скорость: ${car.max_velocity}, Места: ${car.passenger_places}`);
        });
    }

    compare(secindPark: CarPark) {
        return this.cars.length === secindPark.cars.length;
    }
}

class Car implements ICar {
    id: number;
    gos_number: string;
    mark: string;
    vloume_engine: number;
    max_velocity: number;
    passenger_places: number;

    static lastId: number = 0;

    constructor(gos_number: string, mark: string, vloume_engine: number, max_velocity: number, passenger_places: number) {
        this.id = ++Car.lastId;
        this.gos_number = gos_number;
        this.mark = mark;
        this.vloume_engine = vloume_engine;
        this.max_velocity = max_velocity;
        this.passenger_places = passenger_places;
    }
}


const carPark1 = new CarPark();
const car1 = new Car("333-sada", "Toyota", 1.6, 120, 5);
const car2 = new Car("d123-2226", "Honda", 1.8, 150, 7);
const car3 = new Car("pp-9", "BMW", 3.0, 180, 5);

carPark1.addCar(car1);
carPark1.addCar(car2);
carPark1.addCar(car3);

carPark1.sortCars(true);
carPark1.printCars();

const carPark2 = new CarPark();
const car4 = new Car("sdaq22s-02", "Ford", 2.0, 160, 5);
const car5 = new Car("d2d-35", "Chevrolet", 2.5, 170, 7);
const car6 = new Car("asd-8", "Audi", 3.5, 200, 4);

carPark2.addCar(car4);
carPark2.addCar(car5);
carPark2.addCar(car6);


const areParksEqual = carPark1.compare(carPark2);
console.log(`Равны ли автопарки: ${areParksEqual}`);