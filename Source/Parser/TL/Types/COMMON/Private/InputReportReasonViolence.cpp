#include "../Public/InputReportReasonViolence.h"


//begin namespace block
namespace COMMON
{

InputReportReasonViolence::InputReportReasonViolence()
{
	this->_ConstructorID = 505595789;
}
void InputReportReasonViolence::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputReportReasonViolence::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
InputReportReasonViolence::~InputReportReasonViolence()
{
}
}//end namespace block
