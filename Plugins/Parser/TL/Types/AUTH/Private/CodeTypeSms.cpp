#include "../Public/CodeTypeSms.h"


//begin namespace block
namespace AUTH
{

CodeTypeSms::CodeTypeSms()
{
	this->_ConstructorID = -1944738958;
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
}
CodeTypeSms::~CodeTypeSms()
{

}
}//end namespace block
