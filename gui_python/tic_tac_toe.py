import tkinter as tk
from tkinter import messagebox


# Initialize the main window of the game

root = tk.Tk()
root.title("Tic Tac Toe")

for i in range(3):
    root.rowconfigure(i, weight=1)
    root.columnconfigure(i, weight=1)

current_player = "X"
board = [
    ["", "", ""], # [(0,0), (0,1), (0,2)]
    ["", "", ""], # [(1,0), (1,1), (1,2)]
    ["", "", ""]  # [(2,0), (2,1), (2,2)]
]

buttons = []
for i in range(3):
    row_buttons = []
    for j in range(3):
        btn = tk.Button(root, text="", width=5, height=2, font=("Arial", 24))
        btn.config(command=lambda r=i, c=j, b=btn: button_click(r, c, b))
        btn.grid(row=i, column=j, sticky="nsew")
        row_buttons.append(btn)
    buttons.append(row_buttons)

def is_draw():
    not_empty=0
    for i in range(3):
        for l in range(3):
            if board[i][l]=="":
                not_empty=not_empty+1
    if not_empty!=0:
        return False
    else:
        return True


def is_winner(player):
    if board[0][0] == player and board[1][1] == player and board[2][2]==player:
        return True
    if board[0][2] == player and board[1][1] == player and board[2][0]==player:
        return True
    
    for i in range(3):
        k=0
        p=0
        for t in range(3):
            if board[i][t]==player:
                k=k+1
            if board[t][i]==player:
                p=p+1
        if k==3:
            return True   
        if p==3:
            return True
        

def reset_board():
    for i in range(3):
        for l in range(3):
            board[i][l]=""
            buttons[i][l].config(text="", state="normal")
    current_player="X"
    message_label.config(text=f"Player {current_player} turn")
    

def disable_buttons():
    for i in range(3):
        for l in range(3):
            buttons[i][l].config(state="disabled")

def button_click(row, col, button):
    global current_player

    if board[row][col] == "":
        board[row][col] = current_player
        button.config(text=current_player)
        
        if is_winner(current_player):
           # messagebox.showinfo("Game Over", f"Player {current_player} wins!")
            message_label.config(text=f"Player {current_player} wins!")
            disable_buttons()
        elif is_draw():
            #messagebox.showinfo("Game Over", "It's a draw!")
            message_label.config(text=f"it is a draw")
            disable_buttons()
        else:
            
            if current_player == "X":
                current_player = "O"
            else:
                current_player = "X"
            
            message_label.config(text=f"Player {current_player} turn")


message_label = tk.Label(root, text=f"Player {current_player} turn", font=("Arial", 16))
message_label.grid(row=3, column=0, columnspan=3, sticky="nsew")

reset_button = tk.Button(root, text="Reset", font=("Arial", 16), command=reset_board)
reset_button.grid(row=4, column=0, columnspan=3, sticky="nsew")

root.rowconfigure(3, weight=0)  # Fix height of the message label
root.rowconfigure(4, weight=0)  # Fix height of the reset button
root.columnconfigure(0, weight=1)
root.columnconfigure(1, weight=1)
root.columnconfigure(2, weight=1)

root.mainloop()

