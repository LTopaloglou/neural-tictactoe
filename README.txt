DESCRIPTION:
This is a tic-tac-toe game where you play against a neural network.
The neural network is trained on data created by randomly playing
moves, and a min/max algorithm is used to determine the ideal outputs
of our network and calculate cost thereafter.
The neural network is currently set to have two hidden layers with 9 nodes each,
but the NeuralNet class allows you to easily add more hidden layers with
however many nodes you like.

HOW TO USE:
Enter how many games (until completion) that you want in the training dataset.
Next enter how many first turns you want in the dataset.
It will take some time to generate this training data & train the model.
Now you can play against the neural net that was just trained.
Enter an integer to indicate which tile you want to play in according to the diagram below:

_______
|0|1|2|
|_|_|_|
|3|4|5|
|_|_|_|
|6|7|8|
|_|_|_|

At the end of the game, indicate if you would like to play again.

TIP:
I find that 100 full games & 200 first turns is enough to make the
AI play decently well but still beatable