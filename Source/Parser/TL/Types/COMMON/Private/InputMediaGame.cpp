#include "../Public/InputMediaGame.h"


//begin namespace block
namespace COMMON
{

InputMediaGame::InputMediaGame()
{
	this->_ConstructorID = -750828557;
}

InputMediaGame::InputMediaGame(PRIVATE::InputGame*  id)
{
	this->_ConstructorID = -750828557;
	this->id = id;
}
void InputMediaGame::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->id->OnSend(Writer);
}


void InputMediaGame::OnResponce(BinaryReader& Reader)
{
	id = reinterpret_cast<PRIVATE::InputGame* >(Reader.TGReadObject());
	this->_Responded = true;
}
InputMediaGame::~InputMediaGame()
{

}
}//end namespace block
