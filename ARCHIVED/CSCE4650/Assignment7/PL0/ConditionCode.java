// ConditionCode.java

import java.util.*;

// ConditionCode is a class to represent the intermediate code and 
// true and false labels for PL/0 conditonal expressions.

public class ConditionCode {

  private String code;
  private String falseLabel,trueLabel;

  public ConditionCode (String code, String trueLabel, String falseLabel) {
    this . code = code;
    this . trueLabel = trueLabel;
    this . falseLabel = falseLabel;
  }

  public String code () { return code; }

  public String falseLabel () { return falseLabel; }

  public String trueLabel () { return trueLabel; }

}
