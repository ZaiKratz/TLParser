#include "../Public/TopPeerCategoryBotsPM.h"


//begin namespace block
namespace COMMON
{

TopPeerCategoryBotsPM::TopPeerCategoryBotsPM()
{
	this->_ConstructorID = -1419371685;
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
	this->_Responded = true;
}
TopPeerCategoryBotsPM::~TopPeerCategoryBotsPM()
{
}
}//end namespace block
