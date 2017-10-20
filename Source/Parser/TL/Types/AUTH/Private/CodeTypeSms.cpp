#include "../Public/CodeTypeSms.h"


//begin namespace block
namespace AUTH
{

CodeTypeSms::CodeTypeSms()
{
	this->_ConstructorID = 1923290508;
}
void CodeTypeSms::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void CodeTypeSms::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
CodeTypeSms::~CodeTypeSms()
{
}
}//end namespace block
