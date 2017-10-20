#include "../Public/InputMediaGame.h"


//begin namespace block
namespace COMMON
{

InputMediaGame::InputMediaGame()
{
	this->_ConstructorID = -750828557;
}

InputMediaGame::InputMediaGame(TLBaseObject*  id)
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
	id = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	this->_Responded = true;
}
InputMediaGame::~InputMediaGame()
{
	if(this->id)
	{
		delete this->id;
	}
}
}//end namespace block
