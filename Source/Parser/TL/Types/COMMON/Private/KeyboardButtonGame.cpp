#include "../Public/KeyboardButtonGame.h"


//begin namespace block
namespace COMMON
{

KeyboardButtonGame::KeyboardButtonGame()
{
	this->_ConstructorID = 1358175439;
}

KeyboardButtonGame::KeyboardButtonGame(FString text)
{
	this->_ConstructorID = 1358175439;
	this->text = text;
}
void KeyboardButtonGame::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->text);
}


void KeyboardButtonGame::OnResponce(BinaryReader& Reader)
{
	text = Reader.TGReadString();
	this->_Responded = true;
}
KeyboardButtonGame::~KeyboardButtonGame()
{

}
}//end namespace block
