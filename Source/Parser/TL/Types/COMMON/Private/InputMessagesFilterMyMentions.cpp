#include "../Public/InputMessagesFilterMyMentions.h"


//begin namespace block
namespace COMMON
{

InputMessagesFilterMyMentions::InputMessagesFilterMyMentions()
{
	this->_ConstructorID = -1040652646;
}
void InputMessagesFilterMyMentions::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputMessagesFilterMyMentions::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
InputMessagesFilterMyMentions::~InputMessagesFilterMyMentions()
{
}
}//end namespace block
