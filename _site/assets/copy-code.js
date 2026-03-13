// This script adds a "Copy" button to each code block on the page, allowing users to easily copy the code to their clipboard.

document.addEventListener("DOMContentLoaded", function () {

  document.querySelectorAll("pre").forEach(function(pre) {

    const wrapper = document.createElement("div");
    wrapper.className = "code-wrapper";

    pre.parentNode.insertBefore(wrapper, pre);
    wrapper.appendChild(pre);

    const button = document.createElement("button");
    button.innerText = "☐";
    button.className = "copy-button";

    button.onclick = function () {
      const code = pre.querySelector("code").innerText;
      navigator.clipboard.writeText(code);
      button.innerText = "☒";
      setTimeout(() => button.innerText = "☐", 1200);
    };

    wrapper.appendChild(button);

  });

});