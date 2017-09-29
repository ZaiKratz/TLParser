#include "../Public/InputReportReasonOther.h"


//begin namespace block
namespace COMMON
{

InputReportReasonOther::InputReportReasonOther()
{
	this->_ConstructorID = -512463606;
}

InputReportReasonOther::InputReportReasonOther(FString text)
{
	this->_ConstructorID = -512463606;
	this->text = text;
}
void InputReportReasonOther::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->text);
}


void InputReportReasonOther::OnResponce(BinaryReader& Reader)
{
	text = Reader.TGReadString();
	this->_Responded = true;
}
InputReportReasonOther::~InputReportReasonOther()
{

}
}//end namespace block
