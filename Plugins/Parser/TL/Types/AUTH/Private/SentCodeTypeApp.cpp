#include "../Public/SentCodeTypeApp.h"


//begin namespace block
namespace AUTH
{

SentCodeTypeApp::SentCodeTypeApp()
{
	this->_ConstructorID = -2040939715;
}

SentCodeTypeApp::SentCodeTypeApp(int32 length)
{
	this->_ConstructorID = -2040939715;
	this->length = length;
}
void SentCodeTypeApp::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->length);
}


void SentCodeTypeApp::OnResponce(BinaryReader& Reader)
{
	length = Reader.ReadInt();
}
SentCodeTypeApp::~SentCodeTypeApp()
{

}
}//end namespace block
