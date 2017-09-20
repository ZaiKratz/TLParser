#include "../Public/InputNotifyChats.h"


//begin namespace block
namespace COMMON
{

InputNotifyChats::InputNotifyChats()
{
	this->_ConstructorID = 1323865418;
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
}
InputNotifyChats::~InputNotifyChats()
{

}
}//end namespace block
