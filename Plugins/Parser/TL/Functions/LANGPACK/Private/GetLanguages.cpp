#include "../Public/GetLanguages.h"


//begin namespace block
namespace LANGPACK
{

GetLanguages::GetLanguages()
{
	this->_ConstructorID = 2111115136;
	this->_ContentRelated = true;
}
void GetLanguages::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void GetLanguages::OnResponce(BinaryReader& Reader)
{
}
GetLanguages::~GetLanguages()
{

}
}//end namespace block
