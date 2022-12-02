import React, {useState, useEffect} from 'react';
import './TicTacToe.css';


var ganhador = null;




function handleClick(data) {
    
  // Send data to the backend via POST
  fetch('https://43u6xt-3071.preview.csb.app/api/v1/update', {

    method: 'POST',
        
    body:JSON.stringify({
      vencedor: data,
    })

    })
  }


function TicTacToe() { 
  const emptyBoard = Array(9).fill("");

  const [board, setBoard] = useState(emptyBoard);
  const [currentPlayer, setCurrentPlayer] = useState("O");
  const [winner, setWinner] = useState();

  const handleCellClick = (index) => {
    if(winner) {
      console.log("Jogo finalizado");
      return null;
    }

    if (board[index] !== "") {
      console.log("Posição Ocupada");
      return null;
    }

    setBoard(board.map((item, itemIndex) => itemIndex === index ? currentPlayer : item));
    
    setCurrentPlayer(currentPlayer === "X" ? "O" : "X");
  } 

  const checkWinner = () => {
    const possibleWaysToWin = [
      [board[0], board[1], board[2]],
      [board[3], board[4], board[5]],
      [board[6], board[7], board[8]],

      [board[0], board[3], board[6]],
      [board[1], board[4], board[7]],
      [board[2], board[5], board[8]],

      [board[0], board[4], board[8]],
      [board[2], board[4], board[6]],
    ];

    possibleWaysToWin.forEach(cells => {
      if (cells.every(cell => cell === "O")){ 
        setWinner("O venceu!");
        ganhador = 0;
        handleClick(ganhador);
        console.log("foi");
      }
      if (cells.every(cell => cell === "X")){
        setWinner("X venceu!");
        ganhador = 1;
        handleClick(ganhador);
        console.log("foi");
      }
    });
    checkDraw();
  }

  const checkDraw = () => {
    if (board.every(item => item !== "")) setWinner("E"); 
  }

  useEffect(checkWinner, [board]);

  const resetGame = () => {
    setCurrentPlayer("O");
    setBoard(emptyBoard);
    setWinner(null);

  }


  return (
    <main> 
      <h1 className="title">Jogo da Velha</h1>

      <div className= {`board ${winner ? "game-over" : ""}`}>
        {board.map((item, index) => (
          <div 
            key={index}
            className={`cell ${item}`}
            onClick={() => handleCellClick(index)}
          >
            {item}
          </div>
        ))}
      </div>

      {winner && 
        <footer>
          {winner === "E" ?
            <h2 className="winner-message">
              <span className={winner}>Empatou!</span>
            </h2>
            :
            <h2 className="winner-message">
              <span className={winner}>{winner}</span>
            </h2>
          }

          <button onClick={resetGame}> Recomeçar o Jogo!</button>

        </footer>
      } 
    </main>
  );
}

export default TicTacToe;
