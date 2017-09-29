#include "../Public/GetLanguages.h"


//begin namespace block
namespace LANGPACK
{

GetLanguages::GetLanguages()
{
	this->_ConstructorID = -2146445955;
	this->_ContentRelated = true;
}
void GetLanguages::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void GetLanguages::OnResponce(BinaryReader& Reader)
{
	this->_Responded = true;
}
GetLanguages::~GetLanguages()
{

}
}//end namespace block
