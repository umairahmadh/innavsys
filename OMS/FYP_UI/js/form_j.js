$(document).ready(function(){
    $(document).on("click",".login-button",function(){
        var form=$this.closest("form");
        form.submit();
    });
});