
-- -----------------------------------------------------
-- Schema CarSales
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `CarSales` DEFAULT CHARACTER SET utf8 ;
USE `CarSales` ;

-- -----------------------------------------------------
-- Table `CarSales`.`Employee`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `CarSales`.`Employee` (
  `Number` INT NOT NULL,
  `Name` VARCHAR(50) NULL,
  PRIMARY KEY (`Number`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `CarSales`.`Mechanic`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `CarSales`.`Mechanic` (
  `MechanicNumber` INT NOT NULL,
  PRIMARY KEY (`MechanicNumber`),
  CONSTRAINT `fk_Mechanic_Employee`
    FOREIGN KEY (`MechanicNumber`)
    REFERENCES `CarSales`.`Employee` (`Number`))
;


-- -----------------------------------------------------
-- Table `CarSales`.`Salesman`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `CarSales`.`Salesman` (
  `SalesmanNumber` INT NOT NULL,
  PRIMARY KEY (`SalesmanNumber`),
  CONSTRAINT `fk_Salesman_Employee1`
    FOREIGN KEY (`SalesmanNumber`)
    REFERENCES `CarSales`.`Employee` (`Number`));


-- -----------------------------------------------------
-- Table `CarSales`.`Cars`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `CarSales`.`Cars` (
  `License` VARCHAR(45) NOT NULL,
  `Model` VARCHAR(45) NULL,
  `Manufacturer` VARCHAR(45) NULL,
  `Year` YEAR(4) NULL,
  PRIMARY KEY (`License`));


-- -----------------------------------------------------
-- Table `CarSales`.`RepairJob`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `CarSales`.`RepairJob` (
  `Number` INT NOT NULL,
  `MechanicNumber` INT NULL,
  `License` VARCHAR(45) NULL,
  `Description` VARCHAR(100) NULL,
  `PartsCost` FLOAT NULL,
  `WorkCost` FLOAT NULL,
  PRIMARY KEY (`Number`),
  INDEX `fk_RepairJob_Mechanic1_idx` (`MechanicNumber` ASC) VISIBLE,
  INDEX `fk_RepairJob_Cars1_idx` (`License` ASC) VISIBLE,
  CONSTRAINT `fk_RepairJob_Mechanic1`
    FOREIGN KEY (`MechanicNumber`)
    REFERENCES `CarSales`.`Mechanic` (`MechanicNumber`),
  CONSTRAINT `fk_RepairJob_Cars1`
    FOREIGN KEY (`License`)
    REFERENCES `CarSales`.`Cars` (`License`));


-- -----------------------------------------------------
-- Table `CarSales`.`Client`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `CarSales`.`Client` (
  `ID` INT NOT NULL,
  `Name` VARCHAR(45) NULL,
  `Address` VARCHAR(100) NULL,
  `Phone` INT NULL,
  PRIMARY KEY (`ID`));


-- -----------------------------------------------------
-- Table `CarSales`.`Buys`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `CarSales`.`Buys` (
  `SalesmanNumber` INT NOT NULL,
  `License` VARCHAR(45) NOT NULL,
  `ID` INT NOT NULL,
  `Date` DATE NULL,
  `Price` FLOAT NULL,
  `Value` FLOAT NULL,
  PRIMARY KEY (`SalesmanNumber`, `License`, `ID`),
  INDEX `fk_Buys_Cars1_idx` (`License` ASC) VISIBLE,
  INDEX `fk_Buys_Client1_idx` (`ID` ASC) VISIBLE,
  CONSTRAINT `fk_Buys_Salesman1`
    FOREIGN KEY (`SalesmanNumber`)
    REFERENCES `CarSales`.`Salesman` (`SalesmanNumber`),
  CONSTRAINT `fk_Buys_Cars1`
    FOREIGN KEY (`License`)
    REFERENCES `CarSales`.`Cars` (`License`),
  CONSTRAINT `fk_Buys_Client1`
    FOREIGN KEY (`ID`)
    REFERENCES `CarSales`.`Client` (`ID`));


-- -----------------------------------------------------
-- Table `CarSales`.`Sells`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `CarSales`.`Sells` (
  `SalesmanNumber` INT NOT NULL,
  `License` VARCHAR(45) NOT NULL,
  `ID` INT NOT NULL,
  `Date` DATE NULL,
  `Comission` FLOAT NULL,
  `Value` FLOAT NULL,
  PRIMARY KEY (`SalesmanNumber`, `License`, `ID`),
  INDEX `fk_Sells_Cars1_idx` (`License` ASC) VISIBLE,
  INDEX `fk_Sells_Client1_idx` (`ID` ASC) VISIBLE,
  CONSTRAINT `fk_Sells_Salesman1`
    FOREIGN KEY (`SalesmanNumber`)
    REFERENCES `CarSales`.`Salesman` (`SalesmanNumber`),
  CONSTRAINT `fk_Sells_Cars1`
    FOREIGN KEY (`License`)
    REFERENCES `CarSales`.`Cars` (`License`),
  CONSTRAINT `fk_Sells_Client1`
    FOREIGN KEY (`ID`)
    REFERENCES `CarSales`.`Client` (`ID`));

