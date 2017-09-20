#include "../Public/TopPeerCategoryPhoneCalls.h"


//begin namespace block
namespace COMMON
{

TopPeerCategoryPhoneCalls::TopPeerCategoryPhoneCalls()
{
	this->_ConstructorID = -1935182306;
}
void TopPeerCategoryPhoneCalls::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void TopPeerCategoryPhoneCalls::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
TopPeerCategoryPhoneCalls::~TopPeerCategoryPhoneCalls()
{

}
}//end namespace block
