#include "../Public/InputReportReasonOther.h"


//begin namespace block
namespace COMMON
{

InputReportReasonOther::InputReportReasonOther()
{
	this->_ConstructorID = 174945505;
}

InputReportReasonOther::InputReportReasonOther(FString text)
{
	this->_ConstructorID = 174945505;
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
}
InputReportReasonOther::~InputReportReasonOther()
{

}
}//end namespace block
