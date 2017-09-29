#include "../Public/TopPeerCategoryPhoneCalls.h"


//begin namespace block
namespace COMMON
{

TopPeerCategoryPhoneCalls::TopPeerCategoryPhoneCalls()
{
	this->_ConstructorID = 511092620;
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
	this->_Responded = true;
}
TopPeerCategoryPhoneCalls::~TopPeerCategoryPhoneCalls()
{

}
}//end namespace block
