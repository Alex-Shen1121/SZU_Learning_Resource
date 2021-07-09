
-- -----------------------------------------------------
-- Schema CaseStudy
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `CaseStudy` DEFAULT CHARACTER SET utf8 ;
USE `CaseStudy` ;

-- -----------------------------------------------------
-- Table `CaseStudy`.`Department`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `CaseStudy`.`Department` (
  `DepartmentID` INT NOT NULL,
  `DepartmentName` VARCHAR(45) NULL,
  `ManagerID` INT NULL,
  PRIMARY KEY (`DepartmentID`),
  INDEX `fk_Department_Employee_idx` (`ManagerID` ASC) VISIBLE,
  CONSTRAINT `fk_Department_Employee`
    FOREIGN KEY (`ManagerID`)
    REFERENCES `CaseStudy`.`Employee` (`EmployeeID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `CaseStudy`.`Team`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `CaseStudy`.`Team` (
  `TeamID` INT NOT NULL,
  `TeamName` VARCHAR(45) NULL,
  PRIMARY KEY (`TeamID`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `CaseStudy`.`Employee`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `CaseStudy`.`Employee` (
  `EmployeeID` INT NOT NULL,
  `EmpName` VARCHAR(45) NULL,
  `JobTitle` VARCHAR(45) NULL,
  `DepartmentID` INT NULL,
  `TeamID` INT NULL,
  `DOB` DATE NULL,
  `Phone` INT NULL,
  `Address` VARCHAR(100) NULL,
  PRIMARY KEY (`EmployeeID`),
  INDEX `fk_Employee_Department1_idx` (`DepartmentID` ASC) VISIBLE,
  INDEX `fk_Employee_Team1_idx` (`TeamID` ASC) VISIBLE,
  CONSTRAINT `fk_Employee_Department1`
    FOREIGN KEY (`DepartmentID`)
    REFERENCES `CaseStudy`.`Department` (`DepartmentID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Employee_Team1`
    FOREIGN KEY (`TeamID`)
    REFERENCES `CaseStudy`.`Team` (`TeamID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `CaseStudy`.`Product`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `CaseStudy`.`Product` (
  `ProductID` INT NOT NULL,
  `ProductName` VARCHAR(50) NULL,
  `ProductType` VARCHAR(45) NULL,
  PRIMARY KEY (`ProductID`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `CaseStudy`.`Project`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `CaseStudy`.`Project` (
  `ProjectID` INT NOT NULL,
  `TeamID` INT NULL,
  `StartDate` DATE NULL,
  `EndDate` DATE NULL,
  `ProjectManagerID` INT NULL,
  PRIMARY KEY (`ProjectID`),
  INDEX `fk_Project_Team1_idx` (`TeamID` ASC) VISIBLE,
  INDEX `fk_Project_Employee1_idx` (`ProjectManagerID` ASC) VISIBLE,
  CONSTRAINT `fk_Project_Team1`
    FOREIGN KEY (`TeamID`)
    REFERENCES `CaseStudy`.`Team` (`TeamID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Project_Employee1`
    FOREIGN KEY (`ProjectManagerID`)
    REFERENCES `CaseStudy`.`Employee` (`EmployeeID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `CaseStudy`.`Dependent`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `CaseStudy`.`Dependent` (
  `EmployeeID` INT NOT NULL,
  `DependentName` VARCHAR(45) NULL,
  PRIMARY KEY (`EmployeeID`),
  CONSTRAINT `fk_Dependent_Employee1`
    FOREIGN KEY (`EmployeeID`)
    REFERENCES `CaseStudy`.`Employee` (`EmployeeID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `CaseStudy`.`Skills`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `CaseStudy`.`Skills` (
  `SkillID` INT NOT NULL,
  `SkillName` VARCHAR(45) NULL,
  PRIMARY KEY (`SkillID`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `CaseStudy`.`EmployeeSkill`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `CaseStudy`.`EmployeeSkill` (
  `EmployeeID` INT NOT NULL,
  `SkillID` INT NOT NULL,
  `Level` INT NULL,
  PRIMARY KEY (`EmployeeID`, `SkillID`),
  INDEX `fk_EmployeeSkill_Skills1_idx` (`SkillID` ASC) VISIBLE,
  CONSTRAINT `fk_EmployeeSkill_Employee1`
    FOREIGN KEY (`EmployeeID`)
    REFERENCES `CaseStudy`.`Employee` (`EmployeeID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_EmployeeSkill_Skills1`
    FOREIGN KEY (`SkillID`)
    REFERENCES `CaseStudy`.`Skills` (`SkillID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `CaseStudy`.`EmployeeSkill_copy1`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `CaseStudy`.`EmployeeSkill_copy1` (
  `EmployeeID` INT NOT NULL,
  `SkillID` INT NOT NULL,
  `Level` INT NULL,
  PRIMARY KEY (`EmployeeID`, `SkillID`),
  INDEX `fk_EmployeeSkill_Skills1_idx` (`SkillID` ASC) VISIBLE,
  CONSTRAINT `fk_EmployeeSkill_Employee10`
    FOREIGN KEY (`EmployeeID`)
    REFERENCES `CaseStudy`.`Employee` (`EmployeeID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_EmployeeSkill_Skills10`
    FOREIGN KEY (`SkillID`)
    REFERENCES `CaseStudy`.`Skills` (`SkillID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `CaseStudy`.`ProjectSkill`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `CaseStudy`.`ProjectSkill` (
  `ProjectID` INT NOT NULL,
  `SkillID` INT NOT NULL,
  PRIMARY KEY (`ProjectID`, `SkillID`),
  INDEX `fk_ProjectSkill_Skills1_idx` (`SkillID` ASC) VISIBLE,
  CONSTRAINT `fk_ProjectSkill_Project1`
    FOREIGN KEY (`ProjectID`)
    REFERENCES `CaseStudy`.`Project` (`ProjectID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_ProjectSkill_Skills1`
    FOREIGN KEY (`SkillID`)
    REFERENCES `CaseStudy`.`Skills` (`SkillID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `CaseStudy`.`Customers`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `CaseStudy`.`Customers` (
  `CustomerID` INT NOT NULL,
  `FirstName` VARCHAR(45) NULL,
  `LastName` VARCHAR(45) NULL,
  `Phone` INT NULL,
  `Email` VARCHAR(45) NULL,
  `StreetAddress` VARCHAR(100) NULL,
  `City` VARCHAR(45) NULL,
  `State` VARCHAR(45) NULL,
  PRIMARY KEY (`CustomerID`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `CaseStudy`.`Spouse`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `CaseStudy`.`Spouse` (
  `EmployeeID` INT NOT NULL,
  `SpouseName` VARCHAR(45) NULL,
  PRIMARY KEY (`EmployeeID`),
  CONSTRAINT `fk_Spouse_Employee1`
    FOREIGN KEY (`EmployeeID`)
    REFERENCES `CaseStudy`.`Employee` (`EmployeeID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `CaseStudy`.`Orders`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `CaseStudy`.`Orders` (
  `OrderID` INT NOT NULL,
  `ProductID` INT NULL,
  `CustomerID` INT NULL,
  `OrderDate` DATE NULL,
  `ShipDate` DATE NULL,
  `UnitPrice` FLOAT NULL,
  `Quantity` INT NULL,
  `SalespersonID` INT NULL,
  PRIMARY KEY (`OrderID`),
  INDEX `fk_Orders_Customers1_idx` (`CustomerID` ASC) VISIBLE,
  INDEX `fk_Orders_Product1_idx` (`ProductID` ASC) VISIBLE,
  INDEX `fk_Orders_Employee1_idx` (`SalespersonID` ASC) VISIBLE,
  CONSTRAINT `fk_Orders_Customers1`
    FOREIGN KEY (`CustomerID`)
    REFERENCES `CaseStudy`.`Customers` (`CustomerID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Orders_Product1`
    FOREIGN KEY (`ProductID`)
    REFERENCES `CaseStudy`.`Product` (`ProductID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Orders_Employee1`
    FOREIGN KEY (`SalespersonID`)
    REFERENCES `CaseStudy`.`Employee` (`EmployeeID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


