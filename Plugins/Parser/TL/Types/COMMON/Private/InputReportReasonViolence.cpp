#include "../Public/InputReportReasonViolence.h"


//begin namespace block
namespace COMMON
{

InputReportReasonViolence::InputReportReasonViolence()
{
	this->_ConstructorID = -1916329442;
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
}
InputReportReasonViolence::~InputReportReasonViolence()
{

}
}//end namespace block
