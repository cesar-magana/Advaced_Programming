/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I PROYECTO SUDOKU
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
//#include "config.h"
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stdlib.h>
#include <sys/time.h>
#include <vector>

#define GRID_SIZE         3
#define COL_HEIGHT        (GRID_SIZE*GRID_SIZE)
#define ROW_LENGTH        (GRID_SIZE*GRID_SIZE)
#define SEC_SIZE          (GRID_SIZE*GRID_SIZE)
#define SEC_COUNT         (GRID_SIZE*GRID_SIZE)
#define SEC_GROUP_SIZE    (SEC_SIZE*GRID_SIZE)
#define NUM_POSS          (GRID_SIZE*GRID_SIZE)
#define BOARD_SIZE        (ROW_LENGTH*COL_HEIGHT)
#define POSSIBILITY_SIZE  (BOARD_SIZE*NUM_POSS)
#define FOR(i, n) for( int i = 0, _n = (n); i < _n; i++ )

using namespace std;
class Sudoku;
class Log;
string IntToString(int num);
long Time();
void ShuffleArray(int* array, int size);
bool ReadBoardFromStdIn(int* grid);
int main(int argc, char *argv[]);
void PrintHelp(char* programName);
void PrintVersion();
void PrintAbout();
static inline int CellToColumn(int cell);
static inline int CellToRow(int cell);
static inline int CellToSectionStartCell(int cell);
static inline int CellToSection(int cell);
static inline int RowToFirstCell(int row);
static inline int ColumnToFirstCell(int column);
static inline int SectionToFirstCell(int section);
static inline int GetPossibilityIndex(int valueIndex, int cell);
static inline int RowColumnToCell(int row, int column);
static inline int SectionToCell(int section, int offset);


/**
 * Esta estructura contiene funciones para generar y
 * resolver tableros de sudoku.
 */
//------------------------------------------------------------
class Sudoku 
	{
	public:
		//Variables públicas.
		enum Difficulty {UNKNOWN,SIMPLE,EASY,INTERMEDIATE,EXPERT};
		enum ConsolePrintStyle {ONE_LINE,COMPACT,READABLE,CSV};
		//Funciones públicas.
		Sudoku();
		~Sudoku();
		bool Solve();		
		bool IsSolved();
		bool CreateBoard();
		bool SetBoard(int* initPuzzle);
		int CountSolutions();
		int GetGivenCount();
		int GetSingleCount();
		int GetHiddenSingleCount();
		int GetNakedPairCount();
		int GetHiddenPairCount();
		int GetBoxLineReductionCount();
		int GetPointingPairTripleCount();
		int GetGuessCount();
		int GetBacktrackCount();
		void SetRecordHistory(bool rec_history);
		void SetLogHistory(bool logHist);
		void SetConsolePrintStyle(ConsolePrintStyle ps);
		void Show();
		void ShowSolution();
		void PrintPossibilities();
		void PrintSolveHistory();
		void PrintSolveInstructions();
		Sudoku::Difficulty GetDifficulty();
		string GetDifficultyAsString();

	private:
		//Variables privadas:
		/**
		 * Los 81 enteros que forman el tablero de sudoku.
		 * Valores dados son 1-9, desconocidos 0.
		 * Una vez inicializado no se vuelve a mover.
		*/
		int* grid;
		
		/**
		 * Los 81 enteros que forman el tablero de sudoku.
		 * Aquí se presenta la solución.
		 * Se llena con valores de 1-9.
		 */
		int* solution;

		/**
		 * Profundidad de la recursión a la cual cada uno de los números
		 * en la solución fueron colocados.  Useful for backing
		 * out solve branches that don't lead to a solution.
		 */
		int* solution_round;

		/**
		 * Los 729 enteros que forman las posibles soluciones
		 * para un tablero de sudoku. (9 posibilidades
		 * por cada uno de las 81 casillas).  Si vpossibilities[i]
		 * es 0, entonces la casilla todavía puede ser 
		 * llenada de acuerdo a las reglas del sudoku. 
		 */
		int* possibilities;

		/**
		 * Un vector del tamaño del tablero (81) conteniendo cada uno
		 * los números 0-n exactamente una vez.  
		 */
		int* random_board_array;

		/**
		 * Un vector con un elemento por cada posición (9) en
		 * orden aleatorio.
		 */
		int* random_possibility_array;

		/**
		 * Cuando guardar historia o no.
		 */
		bool record_history;

		/**
		 * Whether or not to print history as it happens
		 */
		bool log_history;

		/**
		 * Lista de movimientos usados para resolver el sudoku.
		 * Esta lista contiene todos los movientos, incluso
		 * ramas que no llevan a una solución.
		 */
		vector<Log*>* vsolve_history;

		/**
		 * Lista de movimientos usados para resolver el sudoku.
		 * Esta lista contiene sólamente los movimientos usados
		 * para resolver el sudoku, pero no contiene 
		 * información de "bad guesses".
		 */
		vector<Log*>* vsolve_instructions;
		ConsolePrintStyle print_style;
		int last_solve_round;

		//Funciones privadas
		void ClearBoard();
		int CountSolutions(int round, bool limit_to_two);
		bool Guess(int round, int guess_number);
		bool IsImpossible();
		void RollbackRound(int round);
		bool PointingRowReduction(int round);
		bool RowBoxReduction(int round);
		bool ColBoxReduction(int round);
		bool PointingColumnReduction(int round);
		bool HiddenPairInRow(int round);
		bool HiddenPairInColumn(int round);
		bool HiddenPairInSection(int round);
		void Mark(int position, int round, int value);
		int FindPositionWithFewestPossibilities();
		bool HandleNakedPairs(int round);
		int CountPossibilities(int position);
		bool ArePossibilitiesSame(int position1, int position2);
		void AddHistoryItem(Log* l);
		void MarkRandomPossibility(int round);
		void ShuffleRandomArrays();
		void Print(int* sudoku);
		void RollbackNonGuesses();
		bool OnlyPossibilityForCell(int round);
		bool OnlyValueInRow(int round);
		bool OnlyValueInColumn(int round);
		bool OnlyValueInSection(int round);
		void ShowHistory(vector<Log*>* v);
		bool RemovePossibilitiesInOneFromTwo(int position1, int position2, int round);
		bool SingleSolveMove(int round);
		bool Solve(int round);
		bool Reset();
};


/**
 * Clase para guardar los logs. 
 * 
 */
//------------------------------------------------------------
class Log 
	{
    public:
			//Variables públicas.
			enum LogType 
				{
				GIVEN,
				SINGLE,
				HIDDEN_SINGLE_ROW,
				HIDDEN_SINGLE_COLUMN,
				HIDDEN_SINGLE_SECTION,
				GUESS,
				ROLLBACK,
				NAKED_PAIR_ROW,
				NAKED_PAIR_COLUMN,
				NAKED_PAIR_SECTION,
				POINTING_PAIR_TRIPLE_ROW,
				POINTING_PAIR_TRIPLE_COLUMN,
				ROW_BOX,
				COLUMN_BOX,
				HIDDEN_PAIR_ROW,
				HIDDEN_PAIR_COLUMN,
				HIDDEN_PAIR_SECTION,
				};
			//Funciones públicas
			int GetRound();
			void Print();
			LogType getType();
			Log(int round, LogType type);
			Log(int round, LogType type, int value, int position);
			~Log();
    private:
			//Variables privadas.
			int round;
			LogType type;
			int value;
			int position;
			//Funciones privadas.
			void init(int round, LogType type, int value, int position);
	};
int GetLogCount(vector<Log*>* v, Log::LogType type);


//------------------------------------------------------------
void PrintVersion(){
}


//------------------------------------------------------------
void PrintAbout(){
}


/**
 * Función para modo consola. Muestra la ayuda.
 */
//------------------------------------------------------------
void PrintHelp(char* name){
	cout << name << " <opciones>" << endl;
	cout << "Lista de comandos disponibles." << endl;
	cout << "  --generate <#>       Genera uno varios tablero de sudoku." << endl;
	cout << "  --solve              Resuelve los tableros de sudoku de stdin." << endl;
	cout << "  --difficulty <D>     Cambia la dificultad cuando se genera: very_easy, easy, normal, hard." << endl;
	cout << "  --show               Muestra el tablero (por default cuando se genera)." << endl;
	cout << "  --dontshow           No muestra el tablero (por default cuando se soluciona)." << endl;
	cout << "  --solution           Muestra la solucion (por default cuando se soluciona)." << endl;
	cout << "  --nosolution         No se muestra la solucion (por default cuando se genera)." << endl;
	cout << "  --stats              Muestra estadisticas" << endl;
	cout << "  --nostats            No muestra estadisticas (por default)" << endl;
	cout << "  --time               Muestra el tiempo de generacion o solucion de un tablero." << endl;
	cout << "  --count-solutions    Cuenta el numero de soluciones." << endl;
	cout << "  --history            Muestra ensayo y error." << endl;
	cout << "  --instructions       Muestra los pasos." << endl;
	cout << "  --log-history        Muestra ensayo y error conforme sucede." << endl;
	cout << "  --one-line           Muestra el tablero en una linea de 81 caracteres." << endl;
	cout << "  --compact            Muestra el tablero en nueve lineas de nueve caracteres" << endl;
	cout << "  --board              Muestra el tablero de manera legible." << endl;
	cout << "  --csv                Muestra el tablero en formato csv." << endl;
	cout << "  --help               Muestra la ayuda." << endl;
	cout << "  --about              Visualiza informacion del proyecto." << endl;
	cout << "  --version            Muestra Version" << endl;
}


/**
 * Constructor de la clase. Crea un nuevo tablero de Sudoku.
 */
//------------------------------------------------------------
Sudoku::Sudoku(){
	grid = new int[BOARD_SIZE];
	solution = new int[BOARD_SIZE];
	solution_round = new int[BOARD_SIZE];
	possibilities = new int[POSSIBILITY_SIZE];
	record_history = false;
	print_style = READABLE;
	random_board_array = new int[BOARD_SIZE];
	random_possibility_array = new int[NUM_POSS];
	vsolve_history = new vector<Log*>();
	vsolve_instructions = new vector<Log*>();
	FOR (i,BOARD_SIZE)
		random_board_array[i] = i;
	FOR (i,NUM_POSS)
		random_possibility_array[i] = i;
}


/**
 * Número de celdas que están
 * fijas en el tablero 
 */
//------------------------------------------------------------
int Sudoku::GetGivenCount(){
	int count = 0;
	FOR (i,BOARD_SIZE)
		if (grid[i] != 0) 
			count++;
	return count;
}


/**
 * Llena el tablero.
 */
//------------------------------------------------------------
bool Sudoku::SetBoard(int* init_grid){
	FOR (i,BOARD_SIZE)
		grid[i] = (init_grid==NULL)?0:init_grid[i];
	return Reset();
}


/**
 * Inicializa el tablero a su estado inicial
 */
//------------------------------------------------------------
bool Sudoku::Reset(){
	FOR (i,BOARD_SIZE)
		{
		solution[i] = 0;
		solution_round[i] = 0;
		}
	FOR (i,POSSIBILITY_SIZE)
		possibilities[i] = 0;
	FOR (i,vsolve_history->size())
		delete vsolve_history->at(i);
	vsolve_history->clear();
	vsolve_instructions->clear();
	int round = 1;
	FOR (position,BOARD_SIZE)
		{
		if (grid[position] > 0)
			{
			int val_index = grid[position]-1;
			int val_pos = GetPossibilityIndex(val_index,position);
			int value = grid[position];
			if (possibilities[val_pos] != 0) 
				return false;
			Mark(position,round,value);
			if (log_history || record_history) 
				AddHistoryItem(new Log(round, Log::GIVEN, value, position));
			}
		}
	return true;
}


/**
 * Regresa el nivel de dificultad.
 */
//------------------------------------------------------------
Sudoku::Difficulty Sudoku::GetDifficulty(){
	if (GetGuessCount() > 0) return Sudoku::EXPERT;
	if (GetBoxLineReductionCount() > 0) return Sudoku::INTERMEDIATE;
	if (GetPointingPairTripleCount() > 0) return Sudoku::INTERMEDIATE;
	if (GetHiddenPairCount() > 0) return Sudoku::INTERMEDIATE;
	if (GetNakedPairCount() > 0) return Sudoku::INTERMEDIATE;
	if (GetHiddenSingleCount() > 0) return Sudoku::EASY;
	if (GetSingleCount() > 0) return Sudoku::SIMPLE;
	return Sudoku::UNKNOWN;
}


/**
 * Regresa la dificultad como string.
 */
//------------------------------------------------------------
string Sudoku::GetDifficultyAsString(){
	Sudoku::Difficulty difficulty = GetDifficulty();
	switch (difficulty){
		case Sudoku::EXPERT: return "Hard"; break;
		case Sudoku::INTERMEDIATE: return "Normal"; break;
		case Sudoku::EASY: return "Easy"; break;
		case Sudoku::SIMPLE: return "Very easy"; break;
		default: return "Unknown"; break;
	}
}


/**
 * Regresa el número de celdas para las cuales la solución ya fue determinada
 */
//------------------------------------------------------------
int Sudoku::GetSingleCount(){
	return GetLogCount(vsolve_instructions, Log::SINGLE);
}


//------------------------------------------------------------
int Sudoku::GetHiddenSingleCount(){
	return	GetLogCount(vsolve_instructions, Log::HIDDEN_SINGLE_ROW) +
					GetLogCount(vsolve_instructions, Log::HIDDEN_SINGLE_COLUMN) +
					GetLogCount(vsolve_instructions, Log::HIDDEN_SINGLE_SECTION);
}


//------------------------------------------------------------
int Sudoku::GetNakedPairCount(){
	return	GetLogCount(vsolve_instructions, Log::NAKED_PAIR_ROW) +
					GetLogCount(vsolve_instructions, Log::NAKED_PAIR_COLUMN) +
					GetLogCount(vsolve_instructions, Log::NAKED_PAIR_SECTION);
}


//------------------------------------------------------------
int Sudoku::GetHiddenPairCount(){
	return	GetLogCount(vsolve_instructions, Log::HIDDEN_PAIR_ROW) +
					GetLogCount(vsolve_instructions, Log::HIDDEN_PAIR_COLUMN) +
					GetLogCount(vsolve_instructions, Log::HIDDEN_PAIR_SECTION);
}


//------------------------------------------------------------
int Sudoku::GetPointingPairTripleCount(){
	return	GetLogCount(vsolve_instructions, Log::POINTING_PAIR_TRIPLE_ROW)+
					GetLogCount(vsolve_instructions, Log::POINTING_PAIR_TRIPLE_COLUMN);
}

//------------------------------------------------------------
int Sudoku::GetBoxLineReductionCount(){
	return	GetLogCount(vsolve_instructions, Log::ROW_BOX)+
					GetLogCount(vsolve_instructions, Log::COLUMN_BOX);
}


//------------------------------------------------------------
int Sudoku::GetGuessCount(){
	return GetLogCount(vsolve_instructions, Log::GUESS);
}


//------------------------------------------------------------
int Sudoku::GetBacktrackCount(){
	return GetLogCount(vsolve_history, Log::ROLLBACK);
}


//------------------------------------------------------------
void Sudoku::MarkRandomPossibility(int round){
	int remaining_possibilities = 0;
	FOR(i,POSSIBILITY_SIZE)
		if (possibilities[i] == 0) 
			remaining_possibilities++;
	int random_possibility = rand()%remaining_possibilities;
	int possibility_to_mark = 0;
	FOR(i,POSSIBILITY_SIZE)
		{
		if (possibilities[i] == 0)
			{
			if (possibility_to_mark == random_possibility)
				{
				int position = i/NUM_POSS;
				int value = i%NUM_POSS+1;
				Mark(position, round, value);
				return;
				}
			possibility_to_mark++;
			}
		}
}


//------------------------------------------------------------
void Sudoku::ShuffleRandomArrays(){
	ShuffleArray(random_board_array, BOARD_SIZE);
	ShuffleArray(random_possibility_array, NUM_POSS);
}


/**
 * Borra cualquier tablero existente anteriormente. 
 */
//------------------------------------------------------------
void Sudoku::ClearBoard()
	{
	FOR (i,BOARD_SIZE)
		grid[i]=0;
	Reset();
	}


/**
 * Inicializa el tablero de sudoku aleatoriamente. 
 */
//------------------------------------------------------------
bool Sudoku::CreateBoard(){
	bool rec_history = record_history;
	SetRecordHistory(false);
	bool l_history = log_history;
	SetLogHistory(false);
	ClearBoard();
	ShuffleRandomArrays();
	Solve();
	RollbackNonGuesses();
	FOR (i,BOARD_SIZE)
		grid[i] = solution[i];
	ShuffleRandomArrays();
	FOR (i,BOARD_SIZE)
		{
		int position = random_board_array[i];
		if (grid[position] > 0)
			{
			int savedValue = grid[position];
			grid[position] = 0;
			Reset();
			if (CountSolutions(2, true) > 1)
				grid[position] = savedValue;
			}
		}
	Reset();
	SetRecordHistory(rec_history);
	SetLogHistory(l_history);
	return true;
}


//------------------------------------------------------------
void Sudoku::RollbackNonGuesses(){
	for (int i=2; i<=last_solve_round; i+=2)
		RollbackRound(i);
}


//------------------------------------------------------------
void Sudoku::SetConsolePrintStyle(ConsolePrintStyle ps){
	print_style = ps;
}


//------------------------------------------------------------
void Sudoku::SetRecordHistory(bool rec_history){
    record_history = rec_history;
}


//------------------------------------------------------------
void Sudoku::SetLogHistory(bool logHist){
    log_history = logHist;
}


//------------------------------------------------------------
void Sudoku::AddHistoryItem(Log* l){
	if (log_history)
		{
		l->Print();
		cout << endl;
		}
	if (record_history)
		{
		vsolve_history->push_back(l);
		vsolve_instructions->push_back(l);
		}
	else 
		delete l;
}


//------------------------------------------------------------
void Sudoku::ShowHistory(vector<Log*>* v){
	if (!record_history)
		{
		cout << "No se guardo la historia.";
		if (print_style == CSV)
			cout << " -- ";
		else 
			cout << endl;
		}
	FOR (i,v->size())
		{
		cout << i+1 << ". ";
		v->at(i)->Print();
		if (print_style == CSV)
			cout << " -- ";
		else 
			cout << endl;
		}
	if (print_style == CSV)
		cout << ",";
	else 
		cout << endl;
}


//------------------------------------------------------------
void Sudoku::PrintSolveInstructions(){
	if (IsSolved())
		ShowHistory(vsolve_instructions);
	else 
		cout << "No existe solucion." << endl;
}


//------------------------------------------------------------
void Sudoku::PrintSolveHistory(){
	ShowHistory(vsolve_history);
}


//------------------------------------------------------------
bool Sudoku::Solve(){
	Reset();
	ShuffleRandomArrays();
	return Solve(2);
}


//------------------------------------------------------------
bool Sudoku::Solve(int round){
	last_solve_round = round;
	while (SingleSolveMove(round))
		{
		if (IsSolved()) return true;
		if (IsImpossible()) return false;
		}
	int next_guess_round = round+1;
	int next_round = round+2;
	for (int guess_number=0; Guess(next_guess_round, guess_number); guess_number++)
		{
		if (IsImpossible() || !Solve(next_round))
			{
			RollbackRound(next_round);
			RollbackRound(next_guess_round);
			} 
		else 
			return true;
		}
	return false;
}



//------------------------------------------------------------
int Sudoku::CountSolutions(){
	bool rec_history = record_history;
	SetRecordHistory(false);
	bool l_history = log_history;
	SetLogHistory(false);
	Reset();
	int solution_count = CountSolutions(2, false);
	SetRecordHistory(rec_history);
	SetLogHistory(l_history);
	return solution_count;
}


//------------------------------------------------------------
int Sudoku::CountSolutions(int round, bool limit_to_two){
	while (SingleSolveMove(round))
		{
		if (IsSolved())
			{
			RollbackRound(round);
			return 1;
			}
		if (IsImpossible())
			{
			RollbackRound(round);
			return 0;
			}
		}
	int solutions = 0;
	int next_round = round+1;
	for (int guess_number=0; Guess(next_round, guess_number); guess_number++)
		{
		solutions += CountSolutions(next_round, limit_to_two);
		if (limit_to_two && solutions >=2)
			{
			RollbackRound(round);
			return solutions;
			}
		}
	RollbackRound(round);
	return solutions;
}



//------------------------------------------------------------
void Sudoku::RollbackRound(int round){
	if (log_history || record_history) AddHistoryItem(new Log(round, Log::ROLLBACK));
	FOR (i,BOARD_SIZE)
		{
		if (solution_round[i] == round)
			{
			solution_round[i] = 0;
			solution[i] = 0;
			}
		}
	FOR (i,POSSIBILITY_SIZE)
		{
		if (possibilities[i] == round)
			possibilities[i] = 0;
		}
	while(vsolve_instructions->size() > 0 && vsolve_instructions->back()->GetRound() == round)
		vsolve_instructions->pop_back();
}


//------------------------------------------------------------
bool Sudoku::IsSolved(){
	FOR (i,BOARD_SIZE)
		{
		if (solution[i] == 0)
				return false;
		}
	return true;
}


//------------------------------------------------------------
bool Sudoku::IsImpossible(){
	FOR (position,BOARD_SIZE)
		{
		if (solution[position] == 0)
			{
			int count = 0;
			FOR (val_index,NUM_POSS)
				{
				int val_pos = GetPossibilityIndex(val_index,position);
				if (possibilities[val_pos] == 0) count++;
				}
			if (count == 0) 
				return true;
			}
		}
	return false;
}


//------------------------------------------------------------
int Sudoku::FindPositionWithFewestPossibilities(){
	int min_possibilities = 10;
	int best_position = 0;
	FOR (i,BOARD_SIZE)
		{
		int position = random_board_array[i];
		if (solution[position] == 0)
			{
			int count = 0;
			FOR (val_index,NUM_POSS)
				{
				int val_pos = GetPossibilityIndex(val_index,position);
				if (possibilities[val_pos] == 0) count++;
				}
			if (count < min_possibilities)
				{
				min_possibilities = count;
				best_position = position;
				}
			}
		}
	return best_position;
}


//------------------------------------------------------------
bool Sudoku::Guess(int round, int guess_number){
	int local_guess_count = 0;
	int position = FindPositionWithFewestPossibilities();
	FOR(i,NUM_POSS)
		{
		int val_index = random_possibility_array[i];
		int val_pos = GetPossibilityIndex(val_index,position);
		if (possibilities[val_pos] == 0)
			{
			if (local_guess_count == guess_number)
				{
				int value = val_index+1;
				if (log_history || record_history) AddHistoryItem(new Log(round, Log::GUESS, value, position));
				Mark(position, round, value);
				return true;
				}
			local_guess_count++;
			}
		}
	return false;
}


//------------------------------------------------------------
bool Sudoku::SingleSolveMove(int round){
	if (OnlyPossibilityForCell(round)) return true;
	if (OnlyValueInSection(round)) return true;
	if (OnlyValueInRow(round)) return true;
	if (OnlyValueInColumn(round)) return true;
	if (HandleNakedPairs(round)) return true;
	if (PointingRowReduction(round)) return true;
	if (PointingColumnReduction(round)) return true;
	if (RowBoxReduction(round)) return true;
	if (ColBoxReduction(round)) return true;
	if (HiddenPairInRow(round)) return true;
	if (HiddenPairInColumn(round)) return true;
	if (HiddenPairInSection(round)) return true;
	return false;
}


//------------------------------------------------------------
bool Sudoku::ColBoxReduction(int round){
	FOR (val_index,NUM_POSS)
		{
		FOR(col,9)
			{
			int col_start = ColumnToFirstCell(col);
			bool in_one_box = true;
			int col_box = -1;
			FOR (i,3)
				{
				FOR(j,3)
					{
					int row = i*3+j;
					int position = RowColumnToCell(row, col);
					int val_pos = GetPossibilityIndex(val_index,position);
					if(possibilities[val_pos] == 0)
						{
						if (col_box == -1 || col_box == i)
							col_box = i;
						else 
							in_one_box = false;
						}
					}
				}
			if (in_one_box && col_box != -1)
				{
				bool finish_something = false;
				int row = 3*col_box;
				int sec_start = CellToSectionStartCell(RowColumnToCell(row, col));
				int sec_start_row = CellToRow(sec_start);
				int sec_start_col = CellToColumn(sec_start);
				FOR (i,3)
					{	
					FOR(j,3)
						{
						int row2 = sec_start_row+i;
						int col2 = sec_start_col+j;
						int position = RowColumnToCell(row2, col2);
						int val_pos = GetPossibilityIndex(val_index,position);
						if (col != col2 && possibilities[val_pos] == 0)
							{
							possibilities[val_pos] = round;
							finish_something = true;
							}
						}//FOR j
					}//FOR i
				if (finish_something)
					{
					if (log_history || record_history) AddHistoryItem(new Log(round, Log::COLUMN_BOX, val_index+1, col_start));
					return true;
					}
				}
			}//FOR col
	}//FOR val_index
	return false;
}


//------------------------------------------------------------
bool Sudoku::RowBoxReduction(int round){
	FOR (val_index,NUM_POSS)
		{
		FOR(row,9)
			{
			int row_start = RowToFirstCell(row);
			bool in_one_box = true;
			int rowBox = -1;
			FOR(i,3)
				{
				FOR (j,3)
					{
					int column = i*3+j;
					int position = RowColumnToCell(row, column);
					int val_pos = GetPossibilityIndex(val_index,position);
					if(possibilities[val_pos] == 0)
						{
						if (rowBox == -1 || rowBox == i)
							rowBox = i;
						else 
							in_one_box = false;
						}
					}//FOR j
				}//FOR i
			if (in_one_box && rowBox != -1)
				{
					bool finish_something = false;
					int column = 3*rowBox;
					int sec_start = CellToSectionStartCell(RowColumnToCell(row, column));
					int sec_start_row = CellToRow(sec_start);
					int sec_start_col = CellToColumn(sec_start);
					FOR (i,3)
						{
						FOR(j,3)
							{
							int row2 = sec_start_row+i;
							int col2 = sec_start_col+j;
							int position = RowColumnToCell(row2, col2);
							int val_pos = GetPossibilityIndex(val_index,position);
							if (row != row2 && possibilities[val_pos] == 0)
								{
								possibilities[val_pos] = round;
								finish_something = true;
								}
							}//FOR j
						}//FOR i
					if (finish_something)
						{
						if (log_history || record_history) AddHistoryItem(new Log(round, Log::ROW_BOX, val_index+1, row_start));
						return true;
						}
				}
			}//FOR row
		}//FOR val_index
	return false;
}


//------------------------------------------------------------
bool Sudoku::PointingRowReduction(int round){
	FOR (val_index,NUM_POSS)
		{
		FOR (section,9)
			{
			int sec_start = SectionToFirstCell(section);
			bool in_one_row = true;
			int boxRow = -1;
			FOR(j,3)
				{
				FOR (i,3)
					{
					int sec_val=sec_start+i+(9*j);
					int val_pos = GetPossibilityIndex(val_index,sec_val);
					if(possibilities[val_pos] == 0)
						{
						if (boxRow == -1 || boxRow == j)
							boxRow = j;
						else 
							in_one_row = false;
						}
					}
				}//FOR j
			if (in_one_row && boxRow != -1)
				{
				bool finish_something = false;
				int row = CellToRow(sec_start) + boxRow;
				int row_start = RowToFirstCell(row);
				FOR (i,9)
					{
					int position = row_start+i;
					int section2 = CellToSection(position);
					int val_pos = GetPossibilityIndex(val_index,position);
					if (section != section2 && possibilities[val_pos] == 0)
						{
						possibilities[val_pos] = round;
						finish_something = true;
						}
					}
				if (finish_something){
						if (log_history || record_history) 
							AddHistoryItem(new Log(round, Log::POINTING_PAIR_TRIPLE_ROW, val_index+1, row_start));
						return true;
				}
				}
			}//FOR section
		}//FOR val_index
	return false;
}


//------------------------------------------------------------
bool Sudoku::PointingColumnReduction(int round){
	FOR (val_index,NUM_POSS)
		{
		FOR(section,9)
			{
			int sec_start = SectionToFirstCell(section);
			bool in_one_col = true;
			int box_col = -1;
			FOR (i,3)
				{
				FOR(j,3)
					{
					int sec_val=sec_start+i+(9*j);
					int val_pos = GetPossibilityIndex(val_index,sec_val);
					if(possibilities[val_pos] == 0)
						{
						if (box_col == -1 || box_col == i)
							box_col = i;
						else 
							in_one_col = false;
						}
					}//FOR j
				}//FOR i
			if (in_one_col && box_col != -1)
				{
				bool finish_something = false;
				int col = CellToColumn(sec_start) + box_col;
				int col_start = ColumnToFirstCell(col);
				FOR(i,9)
					{
					int position = col_start+(9*i);
					int section2 = CellToSection(position);
					int val_pos = GetPossibilityIndex(val_index,position);
					if (section != section2 && possibilities[val_pos] == 0)
						{
						possibilities[val_pos] = round;
						finish_something = true;
						}
					}//FOR i
				if (finish_something)
					{
					if (log_history || record_history) AddHistoryItem(new Log(round, Log::POINTING_PAIR_TRIPLE_COLUMN, val_index+1, col_start));
					return true;
					}
				}
			}//FOR section
		}//FOR val_index
	return false;
}


//------------------------------------------------------------
int Sudoku::CountPossibilities(int position){
	int count = 0;
	FOR (val_index,NUM_POSS)
		{
		int val_pos = GetPossibilityIndex(val_index,position);
		if (possibilities[val_pos] == 0) 
			count++;
		}
	return count;
}


//------------------------------------------------------------
bool Sudoku::ArePossibilitiesSame(int position1, int position2){
	FOR (val_index,NUM_POSS)
		{
			int val_pos1 = GetPossibilityIndex(val_index,position1);
			int val_pos2 = GetPossibilityIndex(val_index,position2);
			if ((possibilities[val_pos1] == 0 || possibilities[val_pos2] == 0) && (possibilities[val_pos1] != 0 || possibilities[val_pos2] != 0))
				return false;
		}
	return true;
}


//------------------------------------------------------------
bool Sudoku::RemovePossibilitiesInOneFromTwo(int position1, int position2, int round){
	bool finish_something = false;
	FOR (val_index,NUM_POSS)
		{
			int val_pos1 = GetPossibilityIndex(val_index,position1);
			int val_pos2 = GetPossibilityIndex(val_index,position2);
			if (possibilities[val_pos1] == 0 && possibilities[val_pos2] == 0)
				{
					possibilities[val_pos2] = round;
					finish_something = true;
				}
	}
	return finish_something;
}


//------------------------------------------------------------
bool Sudoku::HiddenPairInColumn(int round){
	FOR (column,9)
		{
		FOR (val_index,9)
			{
			int r1 = -1;
			int r2 = -1;
			int val_count = 0;
			FOR (row,9)
				{
				int position = RowColumnToCell(row,column);
				int val_pos = GetPossibilityIndex(val_index,position);
				if (possibilities[val_pos] == 0)
					{
					if (r1 == -1 || r1 == row)
						r1 = row;
					else if (r2 == -1 || r2 == row)
						r2 = row;
					val_count++;
					}
				}//FOR row
			if (val_count==2)
				{
				for (int val_index2=val_index+1; val_index2<9; val_index2++)
					{
					int r3 = -1;
					int r4 = -1;
					int val_count2 = 0;
					FOR (row,9)
						{
						int position = RowColumnToCell(row,column);
						int val_pos = GetPossibilityIndex(val_index2,position);
						if (possibilities[val_pos] == 0)
							{
							if (r3 == -1 || r3 == row)
								r3 = row;
							else if (r4 == -1 || r4 == row)
								r4 = row;
							val_count2++;
							}
						}//FOR row
					if (val_count2==2 && r1==r3 && r2==r4)
						{
							bool finish_something = false;
							FOR (val_index3,9)
								{
								if (val_index3 != val_index && val_index3 != val_index2)
									{
									int position1 = RowColumnToCell(r1,column);
									int position2 = RowColumnToCell(r2,column);
									int val_pos1 = GetPossibilityIndex(val_index3,position1);
									int val_pos2 = GetPossibilityIndex(val_index3,position2);
									if (possibilities[val_pos1] == 0)
										{
										possibilities[val_pos1] = round;
										finish_something = true;
										}
									if (possibilities[val_pos2] == 0)
										{
										possibilities[val_pos2] = round;
										finish_something = true;
										}
									}
								}//FOR val_index3
							if (finish_something)
								{
								if (log_history || record_history) AddHistoryItem(new Log(round, Log::HIDDEN_PAIR_COLUMN, val_index+1, RowColumnToCell(r1,column)));
								return true;
								}
						}
					}//for val_index2
				}//if
			}//FOR val_index
		}//FOR column
	return false;
}


//------------------------------------------------------------
bool Sudoku::HiddenPairInSection(int round){
	FOR (section,9)
		{
		FOR (val_index,9)
			{
			int si1 = -1;
			int si2 = -1;
			int val_count = 0;
			FOR (sec_ind,9)
				{
				int position = SectionToCell(section,sec_ind);
				int val_pos = GetPossibilityIndex(val_index,position);
				if (possibilities[val_pos] == 0)
					{
					if (si1 == -1 || si1 == sec_ind)
						si1 = sec_ind;
					else if (si2 == -1 || si2 == sec_ind)
						si2 = sec_ind;
					val_count++;
					}
				}
			if (val_count==2)
				{
				for (int val_index2=val_index+1; val_index2<9; val_index2++)
					{
					int si3 = -1;
					int si4 = -1;
					int val_count2 = 0;
					FOR (sec_ind,9)
						{
						int position = SectionToCell(section,sec_ind);
						int val_pos = GetPossibilityIndex(val_index2,position);
						if (possibilities[val_pos] == 0)
							{
							if (si3 == -1 || si3 == sec_ind)
								si3 = sec_ind;
							else if (si4 == -1 || si4 == sec_ind)
								si4 = sec_ind;							
							val_count2++;
							}
						}//FOR sec_ind
					if (val_count2==2 && si1==si3 && si2==si4)
						{
						bool finish_something = false;
						FOR (val_index3,9)
							{
							if (val_index3 != val_index && val_index3 != val_index2)
								{
								int position1 = SectionToCell(section,si1);
								int position2 = SectionToCell(section,si2);
								int val_pos1 = GetPossibilityIndex(val_index3,position1);
								int val_pos2 = GetPossibilityIndex(val_index3,position2);
								if (possibilities[val_pos1] == 0)
									{
									possibilities[val_pos1] = round;
									finish_something = true;
									}
								if (possibilities[val_pos2] == 0)
									{
									possibilities[val_pos2] = round;
									finish_something = true;
									}
								}
							}
						if (finish_something)
							{
							if (log_history || record_history) 
								AddHistoryItem(new Log(round, Log::HIDDEN_PAIR_SECTION, val_index+1, SectionToCell(section,si1)));
							return true;
							}
						}
					}//for val_index2
				}//if
			}//FOR val_index
		}//FOR section
	return false;
}


//------------------------------------------------------------
bool Sudoku::HiddenPairInRow(int round){
	FOR (row,9)
		{
			FOR(val_index,9)
				{
				int c1 = -1;
				int c2 = -1;
				int val_count = 0;
				FOR (column,9)
					{
					int position = RowColumnToCell(row,column);
					int val_pos = GetPossibilityIndex(val_index,position);
					if (possibilities[val_pos] == 0)
						{
						if (c1 == -1 || c1 == column)
							c1 = column;
						else if (c2 == -1 || c2 == column)
							c2 = column;
						val_count++;
						}
					}//FOR column
				if (val_count==2)
					{
						for (int val_index2=val_index+1; val_index2<9; val_index2++)
							{
							int c3 = -1;
							int c4 = -1;
							int val_count2 = 0;
							FOR (column,9)
								{
								int position = RowColumnToCell(row,column);
								int val_pos = GetPossibilityIndex(val_index2,position);
								if (possibilities[val_pos] == 0)
									{
									if (c3 == -1 || c3 == column)
										c3 = column;
									else if (c4 == -1 || c4 == column)
										c4 = column;
									val_count2++;
									}
								}//FOR column
							if (val_count2==2 && c1==c3 && c2==c4)
								{
								bool finish_something = false;
								FOR (val_index3,9)
									{
									if (val_index3 != val_index && val_index3 != val_index2)
										{
										int position1 = RowColumnToCell(row,c1);
										int position2 = RowColumnToCell(row,c2);
										int val_pos1 = GetPossibilityIndex(val_index3,position1);
										int val_pos2 = GetPossibilityIndex(val_index3,position2);
										if (possibilities[val_pos1] == 0)
											{
											possibilities[val_pos1] = round;
											finish_something = true;
											}
										if (possibilities[val_pos2] == 0)
											{
											possibilities[val_pos2] = round;
											finish_something = true;
											}
										}
									}//FOR val_index3
								if (finish_something)
									{
									if (log_history || record_history) 
										AddHistoryItem(new Log(round, Log::HIDDEN_PAIR_ROW, val_index+1, RowColumnToCell(row,c1)));
									return true;
									}
								}//if val_count2
							}//for val_index2
					}
				}//FOR val_index
		}//FOR row
	return false;
}


//------------------------------------------------------------
bool Sudoku::HandleNakedPairs(int round){
	FOR (position,BOARD_SIZE)
		{
		int possibilities = CountPossibilities(position);
		if (possibilities == 2)
			{
			int row = CellToRow(position);
			int column = CellToColumn(position);
			int section = CellToSectionStartCell(position);
			FOR (position2,BOARD_SIZE)
				{
				if (position != position2)
					{
					int possibilities2 = CountPossibilities(position2);
					if (possibilities2 == 2 && ArePossibilitiesSame(position, position2))
						{
						if (row == CellToRow(position2))
							{
							bool finish_something = false;
							FOR (column2,9)
								{
								int position3 = RowColumnToCell(row,column2);
								if (position3 != position && position3 != position2 && RemovePossibilitiesInOneFromTwo(position, position3, round))
									finish_something = true;
								}//FOR column2
							if (finish_something)
								{
								if (log_history || record_history) 
									AddHistoryItem(new Log(round, Log::NAKED_PAIR_ROW, 0, position));
								return true;
								}
							}
						if (column == CellToColumn(position2))
							{
							bool finish_something = false;
							FOR (row2,9)
								{
								int position3 = RowColumnToCell(row2,column);
								if (position3 != position && position3 != position2 && RemovePossibilitiesInOneFromTwo(position, position3, round))
									finish_something = true;
								}//FOR row2
							if (finish_something)
								{
								if (log_history || record_history) 
									AddHistoryItem(new Log(round, Log::NAKED_PAIR_COLUMN, 0, position));
								return true;
								}
							}
						if (section == CellToSectionStartCell(position2))
							{
							bool finish_something = false;
							int sec_start = CellToSectionStartCell(position);
							FOR(i,3)
								{
								FOR(j,3)
									{
									int position3=sec_start+i+(9*j);
									if (position3 != position && position3 != position2 && RemovePossibilitiesInOneFromTwo(position, position3, round))
										finish_something = true;
									}//FOR j
								}//FOR i
							if (finish_something)
								{
								if (log_history || record_history) 
									AddHistoryItem(new Log(round, Log::NAKED_PAIR_SECTION, 0, position));
								return true;
								}
							}
						}
					}//if
				}//position2
			}//if
		}//FOR position
	return false;
}



/**
 * Marca la celda de un valor que deba estar en una fila dada
 * si la celda existe.
 * Es la celda llamada "hidden single"
 */
//------------------------------------------------------------
bool Sudoku::OnlyValueInRow(int round){
	FOR (row,ROW_LENGTH)
		{
		FOR (val_index,NUM_POSS)
			{
			int count = 0;
			int last_position = 0;
			FOR (col,COL_HEIGHT)
				{
				int position = (row*ROW_LENGTH)+col;
				int val_pos = GetPossibilityIndex(val_index,position);
				if (possibilities[val_pos] == 0)
					{
					count++;
					last_position = position;
					}
				}
			if (count == 1)
				{
				int value = val_index+1;
				if (log_history || record_history) AddHistoryItem(new Log(round, Log::HIDDEN_SINGLE_ROW, value, last_position));
				Mark(last_position, round, value);
				return true;
				}
			}//FOR val_index
	}//FOR row
	return false;
}



/**
 * Marca la ceda que es el valor único para una columna, si
 * la celda existe.
 * Este tipo de celda es llamado "hidden single".
 */
//------------------------------------------------------------
bool Sudoku::OnlyValueInColumn(int round){
	FOR (col,COL_HEIGHT)
		{
		FOR (val_index,NUM_POSS)
			{
			int count = 0;
			int last_position = 0;
			FOR (row,ROW_LENGTH)
				{
				int position = RowColumnToCell(row,col);
				int val_pos = GetPossibilityIndex(val_index,position);
				if (possibilities[val_pos] == 0)
					{
					count++;
					last_position = position;
					}
				}//FOR row
			if (count == 1)
				{
				int value = val_index+1;
				if (log_history || record_history) AddHistoryItem(new Log(round, Log::HIDDEN_SINGLE_COLUMN, value, last_position));
				Mark(last_position, round, value);
				return true;
				}
		} //FOR val_index
	}//FOR col
	return false;
}



/**
 * Marca la ceda que es el valor único para una sección, si
 * la celda existe.
 * Este tipo de celda es llamado "hidden single".
 */
//------------------------------------------------------------
bool Sudoku::OnlyValueInSection(int round){
	FOR (sec,SEC_COUNT)
		{
		int sec_pos = SectionToFirstCell(sec);
		FOR (val_index,NUM_POSS)
			{
			int count = 0;
			int last_position = 0;
			FOR(i,3)
				{
				FOR(j,3)
					{
					int position = sec_pos + i + 9*j;
					int val_pos = GetPossibilityIndex(val_index,position);
					if (possibilities[val_pos] == 0)
						{
						count++;
						last_position = position;
						}
					}//FOR j
				}//FOR i
			if (count == 1)
				{
				int value = val_index+1;
				if (log_history || record_history) AddHistoryItem(new Log(round, Log::HIDDEN_SINGLE_SECTION, value, last_position));
				Mark(last_position, round, value);
				return true;
				}
			}//FOR val_index
		}//FOR sec
	return false;
}



/**
 * Marca la celda que tiene una única posibilidad, si dicha celda existe.
 * Este tipo de celda es llamada "single".
 */
//------------------------------------------------------------
bool Sudoku::OnlyPossibilityForCell(int round){
	FOR (position,BOARD_SIZE)
		{
		if (solution[position] == 0)
			{
			int count = 0;
			int last_value = 0;
			FOR (val_index,NUM_POSS)
				{
				int val_pos = GetPossibilityIndex(val_index,position);
				if (possibilities[val_pos] == 0)
					{
					count++;
					last_value=val_index+1;
					}
				}
			if (count == 1)
				{
				Mark(position, round, last_value);
				if (log_history || record_history) AddHistoryItem(new Log(round, Log::SINGLE, last_value, position));
				return true;
				}
			}
	}
	return false;
}



/**
 * Marca un valor dado en la posición dada.  
 */
//------------------------------------------------------------
void Sudoku::Mark(int position, int round, int value){
	if (solution[position] != 0) throw ("Posicion ya marcada.");
	if (solution_round[position] !=0) throw ("Posicion ya marcada en otra ronda.");
	int val_index = value-1;
	solution[position] = value;
	int poss_ind = GetPossibilityIndex(val_index,position);
	if (possibilities[poss_ind] != 0) throw ("Posicion imposible.");

	// Quita este valor de las posibilidades en la file.
	solution_round[position] = round;
	int row_start = CellToRow(position)*9;
	FOR (col,COL_HEIGHT)
		{
		int row_val=row_start+col;
		int val_pos = GetPossibilityIndex(val_index,row_val);
		if (possibilities[val_pos] == 0)
			possibilities[val_pos] = round;
		}

	// Quita este valor de las posibilidades en la columna.
	int col_start = CellToColumn(position);
	FOR (i,9)
		{
		int colVal=col_start+(9*i);
		int val_pos = GetPossibilityIndex(val_index,colVal);
		if (possibilities[val_pos] == 0)
			possibilities[val_pos] = round;
		}

	// Quita este valor de las posibilidades en la sección.
	int sec_start = CellToSectionStartCell(position);
	FOR (i,3)
		{
		FOR (j,3)
			{
			int sec_val=sec_start+i+(9*j);
			int val_pos = GetPossibilityIndex(val_index,sec_val);
			if (possibilities[val_pos] == 0)
				possibilities[val_pos] = round;
			}
		}

	FOR(val_index,9)
		{
		int val_pos = GetPossibilityIndex(val_index,position);
		if (possibilities[val_pos] == 0)
			possibilities[val_pos] = round;
		}
}


/**
 * Muestra una lista de celdas que no han sido llenadas
 */
//------------------------------------------------------------ 
void Sudoku::PrintPossibilities(){
	int pos_val = 0;
	int value = 0;
	FOR (i,BOARD_SIZE)
		{
		cout << " ";
		FOR (val_index,NUM_POSS)
			{
			pos_val = (9*i)+val_index;
			value = val_index+1;
			if (possibilities[pos_val]==0)
				cout << value;
			else 
					cout << ".";
			}
		if (i != BOARD_SIZE-1 && i%SEC_GROUP_SIZE==SEC_GROUP_SIZE-1)
			cout << endl << "-------------------------------|-------------------------------|-------------------------------" << endl;
		else if (i%9==8)
			cout << endl;
		else if (i%3==2)
			cout << " |";
		}
	cout << endl;
}



/**
 * Pinta un arreglo de enteros como tablero. 
 * Usa las opciones de impresión dadas en los argmumentos.
 */
//------------------------------------------------------------
void Sudoku::Print(int* sudoku){
	FOR (i,BOARD_SIZE)
		{
		if (print_style == READABLE)
			cout << " ";
		if (sudoku[i]==0)
			cout << '.';
		else 
			cout << sudoku[i];
		if (i == BOARD_SIZE-1)
			{
			if (print_style == CSV)
				cout << ",";
			else 
				cout << endl;
			if (print_style == READABLE || print_style == COMPACT)
				cout << endl;
			}
		else if (i%9==8)
			{
			if (print_style == READABLE || print_style == COMPACT)
				cout << endl;
			if (i%SEC_GROUP_SIZE==SEC_GROUP_SIZE-1)
				if (print_style == READABLE)
					cout << "-------|-------|-------" << endl;
			} 
		else if (i%3==2)
			{
			if (print_style == READABLE)
				cout << " |";				
			}
		}
}


/**
 * Muestra el tablero de sudoku.
 */
//------------------------------------------------------------
void Sudoku::Show(){
    Print(grid);
}


/**
 * Muestra la solución en pantalla.
 */
//------------------------------------------------------------
void Sudoku::ShowSolution(){
    Print(solution);
}


//------------------------------------------------------------
Sudoku::~Sudoku(){
	ClearBoard();
	delete grid;
	delete solution;
	delete possibilities;
	delete solution_round;
	delete random_board_array;
	delete random_possibility_array;
	delete vsolve_history;
	delete vsolve_instructions;
}


//------------------------------------------------------------
Log::Log(int r, LogType t){
	init(r,t,0,-1);
}


//------------------------------------------------------------
Log::Log(int r, LogType t, int v, int p){
	init(r,t,v,p);
}


//------------------------------------------------------------
void Log::init(int r, LogType t, int v, int p){
	round = r;
	type = t;
	value = v;
	position = p;
}


//------------------------------------------------------------
Log::~Log(){
}


//------------------------------------------------------------
int Log::GetRound(){
	return round;
}


//------------------------------------------------------------
Log::LogType Log::getType(){
	return type;
}


/**
 * Muestra un elemento del log .  El mensaje usado es
 * determinado por el timpo de elemento log.
 */
//------------------------------------------------------------
void Log::Print(){
	bool printed;
	cout << "Ronda: " << GetRound() << " - ";
	switch(type)
		{
			case GIVEN:
				cout << "Elemento marcado como 'given'";
			break;
			case ROLLBACK:
				cout << "Roll back round";
			break;
			case GUESS:
				cout << "Guess (ronda inicial).";
			break;
			case HIDDEN_SINGLE_ROW:
				cout << "Posibilidad unica para un valor en la fila.";
			break;
			case HIDDEN_SINGLE_COLUMN:
				cout << "Posibilidad unica para un valor en la columna.";
			break;
			case HIDDEN_SINGLE_SECTION:
				cout << "Posibilidad unica para un valor en la seccion.";
			break;
			case SINGLE:
				cout << "Posibilidad unica para una celda.";
			break;
			case NAKED_PAIR_ROW:
				cout << "Remueve posibilidadades para 'naked pair' en la fila.";
			break;
			case NAKED_PAIR_COLUMN:
				cout << "Remueve posibilidadades para 'naked pair' en la columna.";
			break;
			case NAKED_PAIR_SECTION:
				cout << "Remueve posibilidadades para 'naked pair' en la seccion.";
			break;
			case POINTING_PAIR_TRIPLE_ROW: 
				cout << "Remueve posibilidades para una fila porque los valores estan en una seccion.";
			break;
			case POINTING_PAIR_TRIPLE_COLUMN:
				cout << "Remueve posibilidades para una columna porque los valores estan en una seccion.";
			break;
			case ROW_BOX:
				cout << "Remueve posibilidades para una seccion porque todos los valores estan en una fila.";
			break;
			case COLUMN_BOX: 
				cout << "Remueve posibilidades para una seccion porque todos los valores estan en una columna.";
			break;
			case HIDDEN_PAIR_ROW:
				cout << "Remueve posibilidades de 'hidden pair' en una fila.";
			break;
			case HIDDEN_PAIR_COLUMN:
				cout << "Remueve posibilidades de 'hidden pair' en una columna.";
			break;
			case HIDDEN_PAIR_SECTION:
				cout << "Remueve posibilidades de 'hidden pair' en una seccion.";
			break;
			default:
				cout << "!!! ??? !!!";
			break;
		}
	if (value > 0 || position > -1)
		{
		cout << " (";
		printed = false;
		if (position > -1)
			{
			if (printed) cout << " - ";
			cout << "Fila: " << CellToRow(position)+1 << " - Columna: " << CellToColumn(position)+1;
			printed = true;
			}
		if (value > 0)
			{
			if (printed) cout << " - ";
			cout << "Valor: " << value;
			printed = true;
			}
		cout  << ")";
		}
}



/**
 * Dado un vector de Logs, esta función determina
 * cuando logs en el vector son del tipo especificado.
 */
//------------------------------------------------------------
int GetLogCount(vector<Log*>* v, Log::LogType type){
	int count = 0;
	for (unsigned int i=0; i<v->size(); i++)
		if(v->at(i)->getType() == type) count++;
	return count;
}



/**
 * Tiempo del programa en microsegundos.
 */
//------------------------------------------------------------
long Time(){
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec*1000000+tv.tv_usec;
}


/**
 * Intercambia los valores de dos variables.
 */
//------------------------------------------------------------
void Swap( int &x, int &y ){
	x=x+y;
	y=x-y;
	x=x-y;
}


/**
 * Reestructura los valores de un vector.
 */
//------------------------------------------------------------
void ShuffleArray(int* array, int size){
	FOR (i,size)
		{
		int tsize = size-i;
		int rand_pos = rand()%tsize+i;
		swap(array[i],array[rand_pos]);
		}
}

/**
 * Se lee un table desde STDIN.
 * Se procesa un caracter a la vez
 * hasta que se llena el tablero.
 * Se utilizan (0-9) y (.)
 */
//------------------------------------------------------------ 
bool ReadBoardFromStdIn(int* grid){
	int read = 0;
	while (read < BOARD_SIZE)
		{
		//char c = getchar();
		int c = getchar();
		if (c == EOF) return false;
		if (c >= '1' && c <='9')
			{
			grid[read] = c-'0';
			read++;
			}
		if (c == '.' || c == '0')
			{
			grid[read] = 0;
			read++;
			}
		}
	return true;
}


/**
 * Dado el índice de una celda (0-80) calcula
 * la columna (0-8) en la que se encuentra.
 */
//------------------------------------------------------------
static inline int CellToColumn(int cell){
    return cell%COL_HEIGHT;
}


/**
 * Dado el índice de una celda (0-80) calcula
 * la fila (0-8) en la que se encuentra.
 */
//------------------------------------------------------------
static inline int CellToRow(int cell){
	return cell/ROW_LENGTH;
}


/**
 * Dado el índice de una celda (0-80) calcula
 * la sección (0-8) en la que se encuentra.
 */
//------------------------------------------------------------
static inline int CellToSection(int cell){
	return (cell/SEC_GROUP_SIZE*GRID_SIZE) + (CellToColumn(cell)/GRID_SIZE);
}


/**
 * Dado el índice de una celda (0-80) calcula
 * la celda (0-80) que está en la esquina superior izquierda
 * de su sección.
 */
//------------------------------------------------------------
static inline int CellToSectionStartCell(int cell){
	return (cell/SEC_GROUP_SIZE*SEC_GROUP_SIZE) + (CellToColumn(cell)/GRID_SIZE*GRID_SIZE);
}


/**
 * Dada una fila (0-8) calcula la primera celda (0-80)
 * de esa fila.
 */
//------------------------------------------------------------
static inline int RowToFirstCell(int row){
	return 9*row;
}


/**
 * Dada una columna (0-8) calcula la primera celda (0-80)
 * de esa columna.
 */
//------------------------------------------------------------
static inline int ColumnToFirstCell(int column){
	return column;
}


/**
 * Dada una sección (0-8) calcula la primera celda (0-80)
 * de esa sección.
 */
//------------------------------------------------------------
static inline int SectionToFirstCell(int section){
	return (section%GRID_SIZE*GRID_SIZE) + (section/GRID_SIZE*SEC_GROUP_SIZE);
}


/**
 * Dado el valor de una celda (0-8) y una celda (0-80)
 * calcula el 'offset' en el arreglo de posibilidades (0-728).
 */
//------------------------------------------------------------
static inline int GetPossibilityIndex(int valueIndex, int cell){
	return valueIndex+(NUM_POSS*cell);
}


/**
 * Dada una fila (0-8) y una columna (0-8) calcula la
 * celda (0-80).
 */
//------------------------------------------------------------
static inline int RowColumnToCell(int row, int column){
    return (row*COL_HEIGHT)+column;
}


/**
 * Dada una sección (0-8) y un offset en la sección (0-8)
 * calcula la celda (0-80)
 */
//------------------------------------------------------------
static inline int SectionToCell(int section, int offset){
	return SectionToFirstCell(section) + ((offset/GRID_SIZE)*SEC_SIZE) + (offset%GRID_SIZE);
}



//------------------------------------------------------------
//------------------------------------------------------------
int main(int argc, char *argv[]){
	// Declaración de variables.
	
	enum Action {NONE, GENERATE, SOLVE};
	Action action = NONE;
	
	//Dificultad y modo de impresión por default.
	Sudoku::Difficulty difficulty = Sudoku::UNKNOWN;
	Sudoku::ConsolePrintStyle print_style = Sudoku::READABLE;
	
	// Número de tableros para ser generados y resueltos. Número de soluciones.
	int number_generated = 0;	
	int number_to_generate = 1;
	int board_counter = 0;
	int solutions = 0;

	// Inicializa el generador de números aleatorios.
	int time_seed = time(NULL);
		
	// Variables para mostrar las estadísticas.
	int given_count = 0;
	int single_count = 0;
	int hidden_single_count = 0;
	int naked_pair_count = 0;
	int hidden_pair_count = 0;
	int pointing_pair_triple_count = 0;
	int box_reduction_count = 0;
	int guess_count = 0;
	int backtrack_count = 0;


	// Tiempos de ejecucion por tablero
	long board_start_time;
	long board_finish_time;
	
	// Tiempo de ejecucion del programa completo
	long program_start_time; 
	long program_finish_time;
	
	// Muestra tablero, tiempo, solución, historia, instrucciones, estadísticas.
	bool show = false;
	bool show_time = false;
	bool show_history = false;
	bool show_solution = false;
	bool show_instructions = false;
	bool show_stats = false;
	
	// Cuenta las soluciones.
	bool count_solutions = false;
	
	//Registra eventos en un log.
	bool log_history = false;

	// Variable que dice cuando ya terminó.
	bool finish = false;

	bool printed_something = false;
	bool have_grid;


	try 
		{
		program_start_time = Time();

		// Lee los argumentos
		for (int i=1; i<argc; i++)
			{
			if (!strcmp(argv[i],"--board"))
				show = true;
			else if (!strcmp(argv[i],"--solution"))
				show_solution = true;
			else if (!strcmp(argv[i],"--nosolution"))
				show_solution = false;
			else if (!strcmp(argv[i],"--history"))
				show_history = true;
			else if (!strcmp(argv[i],"--nohistory"))
				show_history = false;
			else if (!strcmp(argv[i],"--instructions"))
				show_instructions = true;
			else if (!strcmp(argv[i],"--noinstructions"))
				show_instructions = false;
			else if (!strcmp(argv[i],"--stats"))
				show_stats = true;
			else if (!strcmp(argv[i],"--nostats"))
				show_stats = false;
			else if (!strcmp(argv[i],"--time"))
				show_time = true;
			else if (!strcmp(argv[i],"--count-solutions"))
				count_solutions = true;
			else if (!strcmp(argv[i],"--generate"))
				{
				action = GENERATE;
				show = true;
				if (i+1 < argc && argv[i+1][0] >= '1' && argv[i+1][0] <= '9')
					{
					number_to_generate = atoi(argv[i+1]);
					i++;
					}
				} 
			else if (!strcmp(argv[i],"--difficulty"))
				{
				if (argc < i+1)
					{
					cout << "Por favor especificar una dificultad." << endl;
					return 1;
					} 
				else if (!strcmp(argv[i+1],"very_easy"))
					difficulty = Sudoku::SIMPLE;
				else if (!strcmp(argv[i+1],"easy"))
					difficulty = Sudoku::EASY;
				else if (!strcmp(argv[i+1],"normal"))
					difficulty = Sudoku::INTERMEDIATE;
				else if (!strcmp(argv[i+1],"hard"))
					difficulty = Sudoku::EXPERT;
				else 
					{
					cout << "La dificultad debe ser simple, easy, intermediate, o expert, no " << argv[i+1] << endl;
					return 1;
					}
				i++;
				} 
			else if (!strcmp(argv[i],"--solve"))
				{
				action = SOLVE;
				show_solution = true;
				} 
			else if (!strcmp(argv[i],"--log-history"))
				log_history = true;
			else if (!strcmp(argv[i],"--nolog-history"))
				log_history = false;
			else if (!strcmp(argv[i],"--one-line"))
				print_style=Sudoku::ONE_LINE;
			else if (!strcmp(argv[i],"--compact"))
				print_style=Sudoku::COMPACT;
			else if (!strcmp(argv[i],"--readable"))
				print_style=Sudoku::READABLE;
			else if (!strcmp(argv[i],"--csv"))
				print_style=Sudoku::CSV;
			else if (!strcmp(argv[i],"-n") || !strcmp(argv[i],"--number"))
				{
				if (i+1 < argc)
					number_to_generate = atoi(argv[(i++)+1]);
				else 
					{
					cout << "Especificar un numero." << endl;
					return 1;
					}
				} 
			else if (!strcmp(argv[i],"-h") || !strcmp(argv[i],"--help") || !strcmp(argv[i],"help") || !strcmp(argv[i],"?"))
				{
				PrintHelp(argv[0]);
				return 0;
				} 
			else if (!strcmp(argv[i],"--version"))
				{
				PrintVersion();
				return 0;
				} 
			else if (!strcmp(argv[i],"--about"))
				{
				PrintAbout();
				return 0;
				} 
			else 
				{
				cout << "Argumento desconocido: '" << argv[i] << "'" << endl;
				PrintHelp(argv[0]);
				return 1;
				}
			}//FOR arg

		if (action == NONE)
			{
			cout << "Se tiene que ingresar alguna accion como --solve o --generate." << endl;
			PrintHelp(argv[0]);
			return 1;
			}

		srand(time_seed);

		// Muestra un encabezado si se quiere salida CSV.
		if (print_style == Sudoku::CSV)
			{
			if (show) cout << "Tablero,";
			if (show_solution) cout << "Solucion,";
			if (show_history) cout << "Historial  de solucion,";
			if (show_instructions) cout << "Intrucciones para la solucion,";
			if (count_solutions) cout << "Numero de soluciones,";
			if (show_time) cout << "Tiempo (milisegundos),";
			if (show_stats) cout << "Givens,Singles,Hidden Singles,Naked Pairs,Hidden Pairs,Pointing Pairs/Triples,Box/Line Intersections,Guesses,Backtracks,Dificultad";
			cout << "" << endl;
			}

		//Crea un nuevo tablero de sudoku. Inicializa las variables.
		Sudoku* sudoku_board = new Sudoku();
		sudoku_board->SetRecordHistory(show_history || show_instructions || show_stats || difficulty!=Sudoku::UNKNOWN);
		sudoku_board->SetLogHistory(log_history);
		sudoku_board->SetConsolePrintStyle(print_style);

		// Resuelve tableros hasta dejar de ingresar datos.
		// Genera el número especificado de tableros. 
		finish = false;
		number_generated = 0;
		while (!finish)
			{
			board_start_time = Time();
			printed_something = false;
			have_grid = false;
			if (action == GENERATE)
				{
				//Crea un tablero de sudoku.
				have_grid = sudoku_board->CreateBoard();
				if (!have_grid && show)
					{
					cout << "No fue posible generar el tablero.";
					if (print_style==Sudoku::CSV)
						cout << ",";
					else 
						cout << endl;
					printed_something = true;
					}
				} 
			else 
				{
				// Lee el tablero en STDIN
				int* grid = new int[BOARD_SIZE];
				if (ReadBoardFromStdIn(grid))
					{
					have_grid = sudoku_board->SetBoard(grid);
					if (!have_grid)
						{
						if (show)
							{
							sudoku_board->Show();
							printed_something = true;
							}
						if (show_solution) 
							{
							cout << "Tablero imposible.";
							if (print_style==Sudoku::CSV)
								cout << ",";
							else 
								cout << endl;
							printed_something = true;
							}
						}	
					} 
				else 
					{
					// Si no queda nada en STDIN termina el ciclo
					have_grid = false;
					finish = true;
					}
				//delete grid;
			}

		 solutions = 0;

			if (have_grid)
				{
				// Cuenta soluciones si fue requerido.
				if (count_solutions)
					solutions = sudoku_board->CountSolutions();
				// Resuelve el tablero
				if (show_solution || show_history || show_stats || show_instructions || difficulty!=Sudoku::UNKNOWN)
					sudoku_board->Solve();
				// Tira el tablero si no cumple la exigencias de dificultad
				if (action == GENERATE)
					{
					if (difficulty!=Sudoku::UNKNOWN && difficulty!=sudoku_board->GetDifficulty())
						have_grid = false;
					else 
						{
						number_generated++;
						// Termina ciclo si han sido generados suficientes.
						if (number_generated >= number_to_generate) finish = true;
						}
					}
				}
			if (have_grid)
				{
					// Ya teniendo el tablero
					// muestra solución, estadísticas, etc.
					printed_something = true;
					// Finaliza el tiempo de ejecución del tablero.
					board_finish_time = Time();
					// Muestra el tablero.
					if (show) 
						sudoku_board->Show();

					// Muestra la solución si existe.
					if (show_solution)
						{
						if (sudoku_board->IsSolved())
							sudoku_board->ShowSolution();
						else 
							{
							cout << "El tablero no tiene solucion.";
							if (print_style==Sudoku::CSV)
								cout << ",";
							else 
								cout << endl;
							}
						}
					//Muestra los pasos tomados para resolver o intentar resolver un tablero.
					if (show_history) 
						sudoku_board->PrintSolveHistory();
					// Muestra las instrucciones para resolver un tablero.
					if (show_instructions) 
						sudoku_board->PrintSolveInstructions();
					// Muestra el número de soluciones.
					if (count_solutions)
						{
						if (print_style == Sudoku::CSV)
								cout << solutions << ",";
						else 
							{
							if (solutions == 0)
								cout << "No hay soluciones para este tablero." << endl;
							else if (solutions == 1)
								cout << "La solucion para este tablero es unica." << endl;
							else
								cout << "Hay " << solutions << " soluciones al tablero." << endl;
							}
						}

					// Muestra el tiempo que tomó resolver el tablero.
					if (show_time)
						{
						double t = ((double)(board_finish_time - board_start_time))/1000.0;
						if (print_style == Sudoku::CSV)
							cout << t << ",";
						else 
							cout << "Tiempo: " << t  << " milisegundos." << endl;
						}

					// Muestra las estadísticas.
					if (show_stats)
						{
						given_count = sudoku_board->GetGivenCount();
						single_count = sudoku_board->GetSingleCount();
						hidden_single_count = sudoku_board->GetHiddenSingleCount();
						naked_pair_count = sudoku_board->GetNakedPairCount();
						hidden_pair_count = sudoku_board->GetHiddenPairCount();
						pointing_pair_triple_count = sudoku_board->GetPointingPairTripleCount();
						box_reduction_count = sudoku_board->GetBoxLineReductionCount();
						guess_count = sudoku_board->GetGuessCount();
						backtrack_count = sudoku_board->GetBacktrackCount();
						string difficultyString = sudoku_board->GetDifficultyAsString();
						if (print_style == Sudoku::CSV)
							{
							cout << given_count << ","  << single_count << "," << hidden_single_count
											<< "," << naked_pair_count << "," << hidden_pair_count
											<< ","  << pointing_pair_triple_count  << ","  << box_reduction_count
											<< "," << guess_count << "," << backtrack_count
											<< "," << difficultyString << ",";
							} 
						else 
							{
							cout << "Givens: " << given_count  << endl;
							cout << "Singles: " << single_count << endl;
							cout << "Hidden Singles: " << hidden_single_count  << endl;
							cout << "Naked Pairs: " << naked_pair_count  << endl;
							cout << "Hidden Pairs: " << hidden_pair_count  << endl;
							cout << "Pointing Pairs/Triples: " << pointing_pair_triple_count  << endl;
							cout << "Box/Line Intersections: " << box_reduction_count  << endl;
							cout << "Guesses: " << guess_count  << endl;
							cout << "Backtracks: " << backtrack_count  << endl;
							cout << "Dificultad: " << difficultyString  << endl;
							}
						}
					board_counter++;
				}
			if (printed_something && print_style == Sudoku::CSV)
				cout << endl;
			}
		delete sudoku_board;
		program_finish_time = Time();
		// Muestra el tiempo que tomó la aplicacion completa.
		if (show_time)
			{
			double t = ((double)(program_finish_time - program_start_time))/1000.0;
			cout << board_counter << " tablero" << ((board_counter==1)?"":"s") << " " << (action==GENERATE?"generado":"resuelto") << ((board_counter==1)?"":"s") << " en " << t << " milisegundos." << endl;
			}
		} 
	catch (char const* s)
		{
		cout << s <<  endl;
		return 1;
		}
	return 0;
}
//------------------------------------------------------------
