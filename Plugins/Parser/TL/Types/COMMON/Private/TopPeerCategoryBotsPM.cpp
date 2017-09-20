#include "../Public/TopPeerCategoryBotsPM.h"


//begin namespace block
namespace COMMON
{

TopPeerCategoryBotsPM::TopPeerCategoryBotsPM()
{
	this->_ConstructorID = 1528522411;
}
void TopPeerCategoryBotsPM::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void TopPeerCategoryBotsPM::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
TopPeerCategoryBotsPM::~TopPeerCategoryBotsPM()
{

}
}//end namespace block
