# Barn Boss

![C++](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=flat-square&logo=cplusplus&logoColor=white)
![Paradigm](https://img.shields.io/badge/Paradigm-OOP-4CAF50?style=flat-square)
![Type](https://img.shields.io/badge/Type-Console%20Application-4D4D4D?style=flat-square)

An object-oriented C++ console farm management simulation supporting multiple users within a shared economy. Players grow crops, raise livestock, trade on a dynamic market, complete shared tasks, and compete on a global scoreboard—with full state persistence across sessions.

Developed as **Course Project #05** for *Object-Oriented Programming (Practicum)* in Software Engineering at the Faculty of Mathematics and Informatics, Sofia University "St. Kliment Ohridski" (2025/2026).

---

## Demo

<!-- Replace the path below with a screenshot or terminal recording GIF -->
![Barn Boss CLI Preview](assets/demo.gif)

```text
========================================
               BARN BOSS
========================================
> login Ivan 1234
Welcome, Ivan!

> openMarketCatalog
=== MARKET CATALOG ===
1. Wheat Seed | Qty: 20 | Price: 10
2. Corn Seed  | Qty: 20 | Price: 15
3. Chicken    | Qty: 10 | Price: 25
4. Cow        | Qty: 5  | Price: 50
5. Wheat      | Qty: 20 | Price: 15
6. Corn       | Qty: 20 | Price: 20
7. Egg        | Qty: 15 | Price: 30
8. Milk       | Qty: 10 | Price: 60

> buyItem 1 2
The purchase was successful!
```

---

## Overview & User Roles

The application supports three user roles with role-based permissions:

* **Player** — Manages a personal **Farm** (initial capacity: 3 cropland, 3 farmland) and **Barn**, starts with **100 Balance** and **0 Score**, trades on the shared market, and completes tasks to climb the scoreboard.
* **MarketManager** *(singleton — max 1 per system)* — Restocks inventory and adjusts product prices on the shared market.
* **TaskManager** *(singleton — max 1 per system)* — Creates and removes tasks on the shared task board.

All user accounts require a unique username and a password of at least **3 characters**.

---

## Commands

### System & Account

| Command | Scope | Description |
| :--- | :--- | :--- |
| `register <user> <pass> <type>` | Guest | Register a `Player`, `MarketManager`, or `TaskManager` |
| `login <user> <pass>` | Guest | Authenticate into an existing account |
| `exit` | Guest / Session | Save world state to file and exit |
| `profileInfo` | All Users | Display current user profile details |
| `changePassword <old> <new>` | All Users | Update the current account's password |
| `logout` | All Users | End the current session without exiting |

### Player

| Command | Description |
| :--- | :--- |
| `checkBalance` / `checkScore` | View current balance or score |
| `checkBarn` / `checkFarm` | Inspect barn inventory or farm capacity and free slots |
| `sowPlant <seedId>` / `addAnimal <animalId>` | Place a seed or animal from the barn onto the farm |
| `harvest` | Collect ready produce into the barn and clear harvested slots |
| `expandCropland` / `expandFarmland` | Add `+1` slot to cropland or farmland |
| `openMarketCatalog` | View all market items, quantities, and prices |
| `buyItem <productId> <qty>` | Purchase items from the market |
| `sellItem <productId> <qty>` | Sell barn items back to the market (increases market stock) |
| `showTaskBoard` | List all active tasks and their rewards |
| `completeTask <taskId>` | Deliver required items from the barn to claim rewards |
| `showScoreboard` | Display global player rankings |

### Managers

| Command | Role | Description |
| :--- | :--- | :--- |
| `openMarketCatalog` | `MarketManager` | View current market inventory and prices |
| `restock <productId> <qty>` | `MarketManager` | Add stock to a market product |
| `changePrice <productId> <price>` | `MarketManager` | Set a new price for a market product |
| `showTasks` | `TaskManager` | View all active tasks on the task board |
| `addTask <product> <qty> <bal> <score>` | `TaskManager` | Publish a new task with balance and score rewards |
| `removeTask <taskId>` | `TaskManager` | Remove a task from the board |

---

## Game Mechanics

### Game Cycles
Time progresses independently for each player in **cycles**. Every valid action command (buying, selling, planting, adding animals, expanding, harvesting, completing tasks) advances that player's cycle by `+1`, incrementing the growth progress of all their active plants and animals. Informational commands (`checkBalance`, `checkScore`, `checkBarn`, `checkFarm`, `profileInfo`, `openMarketCatalog`, `showTaskBoard`, `showScoreboard`) and failed commands do not advance the cycle.

### Crops & Livestock

| ID | Item | Initial Price | Required Cycles | Harvest Yield |
| :---: | :--- | :---: | :---: | :--- |
| `1` | Wheat Seed | 10 | 3 | 1× Wheat |
| `2` | Corn Seed | 15 | 4 | 1× Corn |
| `3` | Chicken | 25 | 3 | 1× Egg |
| `4` | Cow | 50 | 5 | 1× Milk |

### Farm Expansion
* **Cost:** `50 × current capacity`
* **Score Requirement:** `10 × current capacity`
* **Effect:** Increases capacity by `+1`.

### Initial Market Stock

| Product | Initial Qty | Initial Price |
| :--- | :---: | :---: |
| Wheat Seed / Corn Seed | 20 / 20 | 10 / 15 |
| Chicken / Cow | 10 / 5 | 25 / 50 |
| Wheat / Corn | 20 / 20 | 15 / 20 |
| Egg / Milk | 15 / 10 | 30 / 60 |

Out-of-stock items (`Qty: 0`) cannot be purchased until restocked by the `MarketManager` or sold back by players.

### Tasks, Scoreboard & Persistence
* **Initial Tasks:** Deliver `5 Wheat` (50 Balance, 10 Score) and `3 Milk` (120 Balance, 20 Score). Completing tasks is the sole way to earn **Score**.
* **Scoreboard:** Ranks `Player` accounts only (managers are excluded) by **Score** (descending) → **Balance** (descending) → **User ID** (ascending).
* **Persistence:** On `exit`, the full world state is saved to disk. On launch, the saved state is restored automatically—or a fresh world is initialized if no save file exists.

---

## Architecture

The codebase is modularized into OOP classes and design patterns:

* **Core & Command Handling:** `Game`, `Command`, `CommandFactory`, `Namespaces`[cite: 1]
* **User Hierarchy & Management:** `User` (base), `Player`, `MarketManager`, `TaskManager`, plus `UserManager` and `UserFactory`[cite: 1]
* **Farm & Entities:** `Farm`, `Barn`, `Entity` (base), `PlantEntity`, `AnimalEntity`[cite: 1]
* **Economy & Progression:** `Market`, `MarketItem`, `Task`, `Taskboard`, `Scoreboard`[cite: 1]

---

## Requirements & Running

**Visual Studio**
1. Clone the repository.
2. Open `BarnBossGame_GeorgiD.vcxproj` in Visual Studio[cite: 1].
3. Build and run the project.

**g++ / MinGW**
```bash
g++ *.cpp -o barn_boss
./barn_boss
```

---

## Author

Georgi Nikolaev Dimitrov, 2nd year at Faculty of Mathematics and Informatics, Sofia University
