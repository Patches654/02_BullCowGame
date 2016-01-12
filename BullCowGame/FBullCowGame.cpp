#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries;}
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

// receives a VALID guess, incriments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// incriment the turn number
	MyCurrentTry++;

	// setup a return variable
	FBullCowCount BullCowCount;
	
	// loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 GuessChar = 0; GuessChar < HiddenWordLength; GuessChar++) {
		// compare letters against the hidden word
		for (int32 HWChar = 0; HWChar < HiddenWordLength; HWChar++) {
			// if the letters match
			if (Guess[GuessChar] == MyHiddenWord[GuessChar]) {
				if (GuessChar == HWChar) { 
					// increase bulls if they are in the same position
					BullCowCount.Bulls++;
				} else {
					// increase cows otherwise (in different positions)
					BullCowCount.Cows++; 
				}
			}
		}
	}
	return BullCowCount;
}
