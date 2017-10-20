#include "../Public/InputNotifyChats.h"


//begin namespace block
namespace COMMON
{

InputNotifyChats::InputNotifyChats()
{
	this->_ConstructorID = 1251338318;
}
void InputNotifyChats::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputNotifyChats::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
InputNotifyChats::~InputNotifyChats()
{
}
}//end namespace block
