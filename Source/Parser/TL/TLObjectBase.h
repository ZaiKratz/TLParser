#pragma once
#include "Engine.h"
#include "../Public/extensions/BinaryReader.h"
#include "../Public/extensions/BinaryWriter.h"

class TLBaseObject 
{
public:
	void OnSendSuccess();
	void OnConfirm();
	bool NeedResend();

// 	virtual void DoDict()
// 	{
// 
// 	}

	virtual void OnSend(BinaryWriter& Writer)
	{

	}

	virtual void OnResponce(BinaryReader& Reader)
	{

	}

public:
	uint32 _ConstructorID;
	bool _ContentRelated;
	bool _Responded;

public:
	bool _Sent;
	long long  _RequestMessageId;
	bool _Dirty;
	FDateTime _SendTime;
	bool _ConfirmReceived;
};