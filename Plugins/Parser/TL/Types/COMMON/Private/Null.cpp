#include "../Public/Null.h"


//begin namespace block
namespace COMMON
{

Null::Null()
{
	this->_ConstructorID = -871664810;
}
void Null::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void Null::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
Null::~Null()
{

}
}//end namespace block
