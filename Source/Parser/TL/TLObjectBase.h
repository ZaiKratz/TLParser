#pragma once
#pragma warning(disable:4946)
#include "Engine.h"
#include "../Public/extensions/BinaryReader.h"
#include "../Public/extensions/BinaryWriter.h"
#include "../Private/SafeBool.h"


class TLBaseObject : public SafeBool<>
{
public:
	void OnSendSuccess();
	void OnConfirm();
	bool NeedResend();

	bool IsValid() const
	{
		return _ConstructorID == 0;
	}

	virtual void OnSend(BinaryWriter& Writer)
	{

	}

	virtual void OnResponce(BinaryReader& Reader)
	{

	}

protected:
	uint32 _ConstructorID;
	bool _ContentRelated;
	bool _Responded;

private:
	bool _Sent;
	long _RequestMessageId;
	bool _Dirty;
	FDateTime _SendTime;
	bool _ConfirmReceived;

};