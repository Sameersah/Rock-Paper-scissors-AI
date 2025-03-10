# Rock-Paper-Scissors AI

##  About the Project
This is an AI-powered Rock-Paper-Scissors game that uses **Machine Learning (ML)** to improve its strategy over time. The application follows **C++ best practices**, **design patterns (Strategy Pattern)**, and an **iterative development approach**.

##  Features
- **Two Strategies:**
    -  **Random Strategy:** Computer picks Rock, Paper, or Scissors at random.
    -  **Smart Strategy:** Learns from human choices and predicts the next move.
- **Strategy Pattern** ensures modularity and flexibility.
- **Persistence:** The smart strategy stores and retrieves data to improve predictions.
- **Command-line Interface (CLI) Game Engine**.
- **Clean Code & Best Practices:** Follows SOLID principles and well-structured project organization.

##  Project Structure
```
Rock-Paper-ScissorsAI/
│── src/              # Source files (C++ implementations)
│   │── main.cpp       # Main game loop
│   │── Game.cpp       # Implementation of Game class
│   │── Strategy.cpp   # Implementation of Strategy base class
│   │── RandomStrategy.cpp # Implementation of Random Strategy
│   │── SmartStrategy.cpp  # Implementation of Smart Strategy
│── include/          # Header files (C++ declarations)
│   │── Game.h        # Declaration of Game class
│   │── Strategy.h    # Declaration of Strategy base class
│   │── RandomStrategy.h # Declaration of Random Strategy
│   │── SmartStrategy.h  # Declaration of Smart Strategy
│── bin/              # Compiled binaries
│── data/             # Storage for frequency files
│   │── strategy_data.txt  # Smart strategy persistent data
│── tests/            # Unit tests
│   │── testGame.cpp       # Unit tests for Game class
│   │── testStrategy.cpp   # Unit tests for strategy classes
│── README.md         # Documentation
│── CMakeLists.txt    # CMake build configuration
```

## ️ Installation & Setup
```sh
# Clone the repository
$ git clone https://github.com/yourusername/Rock-Paper-Scissiors-AI.git

# Navigate to project directory
$ cdRock-Paper-Scissiors-AI

# Compile the project (if using g++)
$ g++ -std=c++11 src/*.cpp -o bin/game

# Run the game
$ ./bin/game
```

## ️ How to Play
1. Run the game from the terminal.
2. Choose a **strategy** before starting (Random or Smart AI).
3. Enter `R`, `P`, or `S` to play Rock, Paper, or Scissors.
4. The AI picks its move and determines the winner.
5. The game continues for **20 rounds**.
6. At the end, scores are displayed.

##  Smart AI Strategy
- The AI **analyzes past moves** and predicts the human player's next choice.
- It **stores move patterns** and adjusts based on frequency.
- The more you play, the **smarter** the AI becomes!

##  Future Enhancements
- Improve AI with **reinforcement learning**.
- Add **GUI version** for better UX.
- Implement **multiplayer mode**.

##  Contributing
Pull requests are welcome! Please follow best practices and provide clear commit messages.

##  License
This project is licensed under the MIT License.

##  Contact
For questions or suggestions, reach out via GitHub Issues or email.
